#!/usr/bin/env python3
# -*- mode: python, encoding: utf-8 -*-
'''
tbrpg – Text based roll playing game

Copyright © 2012  Mattias Andrée (maandree@kth.se)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
'''
import sys
import os


copyNotice = '' 
lineptr = 0
lines = [line.replace('\n', '') for line in sys.stdin.readlines()]

while (len(lines[lineptr]) > 1) and (lines[lineptr][1] == '*'):
    lineptr += 1

copyNotice = '\n'.join(lines[:lineptr])
lines = lines[lineptr:] + ['EOF;']

classLine = None
varLines = None

classes = []
for line in lines:
    if (len(line) == 0) or (line[0] == '\t'):
        continue
    line = line[:line.find(':')] if ':' in line else line
    line = line[:line.find(';')] if ';' in line else line
    classes.append(line.strip())

isObject = set()
idObject = 0
isObject.add('Object')

for line in lines:
    lineptr += 1
    print('\033[1m%i:\033[21m\t%s' % (lineptr, line))
    if len(line) == 0:
        continue
    if line[0] == '\t':
        varLines.append(line[1:])
    elif classLine is None:
        classLine = line
        varLines = []
    else:
        classComment = classLine[classLine.index(';') + 1:].strip()
        classLine = classLine[:classLine.index(';')].strip()
        className = classLine
        supers = []
        superDefault = ''
        superCopy = ''
        superInclude = []
        includes = ['stdlib.h', 'algorithm', 'vector', 'unordered_map']
        includes = ['#include <%s>' % i for i in includes]
        useIncludes = []
        if ':' in className:
            className = className[:className.index(':')]
            superDefault = ' ' + classLine[classLine.index(':'):].replace(', ', '(), ') + '()'
            superCopy = ' ' + classLine[classLine.index(':'):].replace(', ', '(original), ') + '(original)'
            supers = classLine[classLine.index(':') + 2:].replace(',', '').split(' ')
            classLine = classLine.replace(',', ', public').replace(':', ': public')
            superInclude = ['#include "%s.hpp"' % c for c in supers] + ['', ''];
            for superClass in supers:
                if (superClass == 'Object') or (superClass in isObject):
                    isObject.add(className)
        for varLine in varLines:
            varLine = varLine[:varLine.index(';')].strip()
            for s in range(0, len(varLine)):
                if varLine[s] == ' ':
                    space = s
            varType = varLine[:space].replace('[]', '*').replace('*', '')
            for c in classes:
                if (c not in supers) and (c not in useIncludes) and (c != className):
                    if c == varType:
                        useIncludes.append(c)
                    else:
                        for left in '<, ':
                            done = False
                            for right in ', >':
                                if (left + c + right) in varType:
                                    useIncludes.append(c)
                                    done = True
                                    break
                            if done:
                                break
        for deps in (supers, useIncludes):
            for dep in deps:
                sys.stderr.buffer.write(('%s %s\n' % (className, dep)).encode('utf-8'))
        sys.stderr.buffer.flush()
        useIncludes = ['#include "%s.hpp"' % i for i in useIncludes]
        if len(useIncludes) > 0:
            useIncludes += ['', '']
        
        output = '// -*- mode: c++, coding: utf-8 -*-\n'
        output += copyNotice + '\n'
        output += '#ifndef __GUARD_%s_HPP__\n' % className.upper()
        output += '#define __GUARD_%s_HPP__\n' % className.upper()
        output += '\n'
        output += '\n'
        output += '%s\n' % '\n'.join(includes)
        output += '\n'
        output += '%s\n' % '\n'.join(superInclude)
        output += '\n'
        output += '%s\n' % '\n'.join(useIncludes)
        output += '/**\n'
        output += ' * Text based roll playing game\n'
        output += ' * \n'
        output += ' * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n'
        output += ' * \n'
        output += ' * @author  Mattias Andrée <maandree@kth.se>\n'
        output += ' */\n'
        output += 'namespace tbrpg\n'
        output += '{\n'
        output += '  /**\n'
        output += '   * %s\n' % classComment
        output += '   */\n'
        output += '  class %s\n' % classLine
        output += '  {\n'
        output += '  public:\n'
        for varLine in varLines:
            varComment = varLine[varLine.index(';') + 1:].strip()
            varLine = varLine[:varLine.index(';')].strip().replace('[]', '*')
            output += '    /**\n'
            output += '     * %s\n' % varComment
            output += '     */\n'
            output += '    %s;\n' % varLine
            output += '    \n'
        if len(varLines) > 0:
            output += '    \n'
            output += '    \n'
        output += '    /**\n'
        output += '     * Construction\n'
        output += '     */\n'
        output += '    %s();\n' % className
        output += '    \n'
        output += '    /**\n'
        output += '     * Copy constructor\n'
        output += '     * \n'
        output += '     * @param  original  The object to clone\n'
        output += '     */\n'
        output += '    %s(const %s& original);\n' % (className, className)
        output += '    \n'
        output += '    /**\n'
        output += '     * Copy constructor\n'
        output += '     * \n     * @param  original  The object to clone\n'
        output += '     */\n'
        output += '    %s(%s& original);\n' % (className, className)
        output += '    \n'
        output += '    /**\n'
        output += '     * Move constructor\n'
        output += '     * \n'
        output += '     * @param  original  The object to clone\n'
        output += '     */\n'
        output += '    %s(%s&& original);\n' % (className, className)
        output += '    \n'
        output += '    \n'
        output += '    \n'
        output += '    /**\n'
        output += '     * Destructor\n'
        output += '     */\n'
        output += '    virtual ~%s();\n' % className
        output += '    \n'
        output += '    \n'
        output += '    \n'
        output += '    /**\n'
        output += '     * Assignment operator\n'
        output += '     * \n'
        output += '     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */\n'
        output += '    virtual %s& operator =(const %s& original);\n' % (className, className)
        output += '    \n'
        output += '    /**\n'
        output += '     * Assignment operator\n'
        output += '     * \n'
        output += '     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */\n'
        output += '    virtual %s& operator =(%s& original);\n' % (className, className)
        output += '    \n'
        output += '    /**\n'
        output += '     * Move operator\n'
        output += '     * \n'
        output += '     * @param   original  The moved object, its resourced will be moved\n'
        output += '     * @return            The invoked object\n'
        output += '     */\n'
        output += '    virtual %s& operator =(%s&& original);\n' % (className, className)
        output += '    \n'
        output += '    \n'
        output += '    /**\n'
        output += '     * Equality evaluator\n'
        output += '     * \n'
        output += '     * @param   other  The other comparand\n'
        output += '     * @return         Whether the instances are equal\n'
        output += '     */\n'
        output += '    virtual bool operator ==(const %s& other) const;\n' % className
        output += '    \n'
        output += '    /**\n'
        output += '     * Inequality evaluator\n'
        output += '     * \n'
        output += '     * @param   other  The other comparand\n'
        output += '     * @return         Whether the instances are not equal\n'
        output += '     */\n'
        output += '    virtual bool operator !=(const %s& other) const;\n' % className
        output += '    \n'
        output += '    \n'
        output += '  protected:\n'
        output += '    /**\n'
        output += '     * Copy method\n'
        output += '     * \n'
        output += '     * @param  self      The object to modify\n'
        output += '     * @param  original  The reference object\n'
        output += '     */\n'
        output += '    static void __copy__(%s& self, const %s& original);\n' % (className, className)
        output += '    \n'
        output += '    \n'
        output += '  public:\n'
        output += '    /**\n'
        output += '     * Hash method\n'
        output += '     * \n'
        output += '     * @return  The object\'s hash code\n'
        output += '     */\n'
        output += '    size_t hash() const;\n'
        output += '    \n'
        output += '  };\n'
        output += '}\n'
        output += '\n'
        output += 'namespace std\n'
        output += '{\n'
        output += '  template<>\n'
        output += '  class hash<tbrpg::%s>\n' % className
        output += '  {\n'
        output += '  public:\n'
        output += '    size_t operator()(const tbrpg::%s& elem) const\n' % className
        output += '    {\n'
        output += '       return elem.hash();\n'
        output += '    }\n'
        output += '  };\n'
        output += '}\n'
        output += '\n'
        output += '\n'
        output += '#endif//__GUARD_%s_HPP__\n' % className.upper()
        output += '\n'
        modified = False
        if os.path.isfile(className + '.hpp'):
            with open(className + '.hpp', 'rb') as file:
                modified = file.read().decode('utf-8', 'replace') != output
        else:
            modified = True
        if modified:
            with open(className + '.hpp', 'wb') as file:
                file.write(output.encode('utf-8'))
                file.flush()
        
        voidIt = '    (void) original;'
        numericals = ['char', 'byte', 'short', 'int', 'long', 'size_t', 'long long', 'float', 'long float', 'double']
        numericals = ['signed ' + t for t in numericals] + ['unsigned ' + t for t in numericals] + numericals
        (varInit, varCopy, varMove, varFree, classCopy, classMove) = ([], [], [], [], [], [])
        for superClass in supers:
            classCopy.append('%s::__copy__((%s&)*this, (%s&)original);' % (superClass, superClass, superClass))
            classMove.append('std::swap((%s&)*this, (%s&)original);' % (superClass, superClass))
        varNames = []
        for varLine in varLines:
            varLine = varLine[:varLine.index(';')].strip()
            space = 0
            for s in range(0, len(varLine)):
                if varLine[s] == ' ':
                    space = s
            varType = varLine[:space]
            varName = varLine[space + 1:]
            varNames.append(varName)
            if varType == 'bool':
                varInit.append('this->' + varName + ' = false;')
            elif varType in numericals:
                varInit.append('this->' + varName + ' = 0;')
            else:
                varInit.append('this->' + varName + ' = nullptr;')
            varCopy.append('this->%s = original.%s;' % (varName, varName))
            if (varType == 'bool') or (varType in numericals):
                varMove.append('std::swap(this->%s, original.%s);' % (varName, varName))
            else:
                varMove.append('std::swap(this->%s, original.%s);' % (varName, varName))
            if (varType != 'bool') and (varType not in numericals):
                varFree.append('delete this->%s;' % varName)
        varInit = '\n'.join(['    //' + item for item in (['//TO' + 'DO implement constructor'] + varInit)])
        varCopy = '\n'.join(['    ' + item for item in varCopy])
        varMove = '\n'.join(['    ' + item for item in varMove])
        varFree = '\n'.join(['    //' + item for item in (['//TO' + 'DO implement destructor'] + varFree)])
        classCopy = '\n'.join(['    ' + item for item in classCopy])
        classMove = '\n'.join(['    ' + item for item in classMove])
        output = '// -*- mode: c++, coding: utf-8 -*-\n'
        output += copyNotice + '\n'
        output += '#include "%s.hpp"\n' % className
        output += '\n'
        output += '\n'
        output += '/**\n'
        output += ' * Text based roll playing game\n'
        output += ' * \n'
        output += ' * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n'
        output += ' * \n'
        output += ' * @author  Mattias Andrée <maandree@kth.se>\n'
        output += ' */\n'
        output += 'namespace tbrpg\n'
        output += '{\n'
        output += '  /**\n'
        output += '   * Constructor\n'
        output += '   */\n'
        output += '  %s::%s()%s\n' % (className, className, superDefault)
        output += '  {\n'
        if className in isObject:
            output += '    this->class_inheritance.push_back(%i);\n' % idObject
            idObject += 1
        output += '%s\n' % varInit
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Copy constructor\n'
        output += '   * \n'
        output += '   * @param  original  The object to clone\n'
        output += '   */\n'
        output += '  %s::%s(const %s& original)%s\n' % (className, className, className, superCopy)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % varCopy
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Copy constructor\n'
        output += '   * \n'
        output += '   * @param  original  The object to clone\n'
        output += '   */\n'
        output += '  %s::%s(%s& original)%s\n' % (className, className, className, superCopy)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % varCopy
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Move constructor\n'
        output += '   * \n'
        output += '   * @param  original  The object to clone\n'
        output += '   */\n'
        output += '  %s::%s(%s&& original)%s\n' % (className, className, className, superCopy)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % varMove
        output += '  }\n'
        output += '  \n'
        output += '  \n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Destructor\n'
        output += '   */\n'
        output += '  %s::~%s()\n' % (className, className)
        output += '  {\n'
        output += '%s\n' % varFree
        output += '  }\n'
        output += '  \n'
        output += '  \n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Assignment operator\n'
        output += '   * \n'
        output += '   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n'
        output += '   */\n'
        output += '  %s& %s::operator =(const %s& original)\n' % (className, className, className)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % (classCopy + varCopy)
        output += '    return *this;\n'
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Assignment operator\n'
        output += '   * \n'
        output += '   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n'
        output += '   */\n'
        output += '  %s& %s::operator =(%s& original)\n' % (className, className, className)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % (classCopy + varCopy)
        output += '    return *this;\n'
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Move operator\n'
        output += '   * \n'
        output += '   * @param   original  The moved object, its resourced will be moved\n'
        output += '   * @return            The invoked object\n'
        output += '   */\n'
        output += '  %s& %s::operator =(%s&& original)\n' % (className, className, className)
        output += '  {\n'
        output += '%s\n' % voidIt
        output += '%s\n' % (classMove + varMove)
        output += '    return *this;\n'
        output += '  }\n'
        output += '  \n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Equality evaluator\n'
        output += '   * \n'
        output += '   * @param   other  The other comparand\n'
        output += '   * @return         Whether the instances are equal\n'
        output += '   */\n'
        output += '  bool %s::operator ==(const %s& other) const\n' % (className, className)
        output += '  {\n'
        if className == 'Object':
            output += '    return this == &other;\n'
        else:
            for superClass in supers:
                if superClass != 'Object':
                    output += '    if ((%s&)(*this) != (%s&)other)  return false;\n' % (superClass, superClass)
            for varName in varNames:
                output += '    if (this->%s != other.%s)  return false;\n' % (varName, varName)
            output += '    return true;\n'
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Inequality evaluator\n'
        output += '   * \n'
        output += '   * @param   other  The other comparand\n'
        output += '   * @return         Whether the instances are not equal\n'
        output += '   */\n'
        output += '  bool %s::operator !=(const %s& other) const\n' % (className, className)
        output += '  {\n'
        output += '    return (*this == other) == false;\n'
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Copy method\n'
        output += '   * \n'
        output += '   * @param  self      The object to modify\n'
        output += '   * @param  original  The reference object\n'
        output += '   */\n'
        output += '  void %s::__copy__(%s& self, const %s& original)\n' % (className, className, className)
        output += '  {\n'
        output += '    self = original;\n'
        output += '  }\n'
        output += '  \n'
        output += '  /**\n'
        output += '   * Hash method\n'
        output += '   * \n'
        output += '   * @return  The object\'s hash code\n'
        output += '   */\n'
        output += '  size_t %s::hash() const\n' % className
        output += '  {\n'
        if className == 'Object':
            output += '    return (size_t)this;\n'
        else:
            primes = (3, 5, 7, 9, 11, 13, 17, 19)
            pi = 0
            output += '    size_t rc = 0;\n'
            for superClass in supers:
                if superClass != 'Object':
                    output += '    rc = (rc * %i) ^ (rc >> (sizeof(size_t) << 2) * %i);\n' % (primes[pi], primes[pi])
                    output += '    rc += std::hash<%s>()(*this);\n' % superClass
                    pi = (pi + 1) & 7;
            for varLine in varLines:
                varLine = varLine[:varLine.index(';')].strip()
                space = 0
                for s in range(0, len(varLine)):
                    if varLine[s] == ' ':
                        space = s
                varType = varLine[:space]
                varName = varLine[space + 1:]
                output += '    rc = (rc * %i) ^ (rc >> (sizeof(size_t) << 2) * %i);\n' % (primes[pi], primes[pi])
                output += '    rc += std::hash<%s>()(%s);\n' % (varType, varName)
                pi = (pi + 1) & 7;
            output += '    return rc;\n'
        output += '  }\n'
        output += '  \n'
        output += '}\n'
        output += '\n'
        modified = False
        if os.path.isfile(className + '.cc'):
            with open(className + '.cc', 'rb') as file:
                modified = file.read().decode('utf-8', 'replace') != output
        else:
            modified = True
        if modified:
            with open(className + '.cc', 'wb') as file:
                file.write(output.encode('utf-8'))
                file.flush()
        
        classLine = line
        varLines = []

