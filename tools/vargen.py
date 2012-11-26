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
        for varLine in varLines:
            varLine = varLine[:varLine.index(';')].strip()
            for s in range(0, len(varLine)):
                if varLine[s] == ' ':
                    space = s
            varType = varLine[:space].replace('[]', '*').replace('*', '')
            for c in classes:
                if c not in supers:
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
        
        output = '// -*- mode: c++, coding: utf-8 -*-\n' + copyNotice + '\n'
        output += '#ifndef __GUARD_%s_HPP__\n' % className.upper()
        output += '#define __GUARD_%s_HPP__\n' % className.upper()
        output += '\n\n%s\n\n%s\n\n%s\n/**\n' % ('\n'.join(includes), '\n'.join(superInclude), '\n'.join(useIncludes))
        output += ' * Text based roll playing game\n * \n * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n * \n * @author  Mattias Andrée <maandree@kth.se>\n */\n'
        output += 'namespace tbrpg\n{\n'
        output += '  /**\n   * %s\n   */\n  class %s\n  {\n  public:\n' % (classComment, classLine)
        for varLine in varLines:
            varComment = varLine[varLine.index(';') + 1:].strip()
            varLine = varLine[:varLine.index(';')].strip().replace('[]', '*')
            output += '    /**\n     * %s\n     */\n    //%s;\n    \n' % (varComment, varLine)
        if len(varLines) > 0:
            output += '    \n    \n'
        output += '    /**\n     * Construction\n     */\n    %s();\n    \n' % className
        output += '    /**\n     * Copy constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(const %s& original);\n    \n' % (className, className)
        output += '    /**\n     * Copy constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(%s& original);\n    \n' % (className, className)
        output += '    /**\n     * Move constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(%s&& original);\n    \n    \n    \n' % (className, className)
        output += '    /**\n     * Destructor\n     */\n    virtual ~%s();\n    \n    \n    \n' % className
        output += '    /**\n     * Assignment operator\n     * \n     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */\n    virtual %s& operator =(const %s& original);\n    \n' % (className, className)
        output += '    /**\n     * Assignment operator\n     * \n     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */\n    virtual %s& operator =(%s& original);\n    \n' % (className, className)
        output += '    /**\n     * Move operator\n     * \n     * @param   original  The moved object, '
        output += 'its resourced will be moved\n     * @return            The invoked object\n'
        output += '     */\n    virtual %s& operator =(%s&& original);\n    \n' % (className, className)
        output += '    \n  protected:\n    /**\n     * Copy method\n     * \n'
        output += '     * @param  self      The object to modify\n     * @param  original  The reference object\n'
        output += '     */\n    static void __copy__(%s& self, const %s& original);\n    \n' % (className, className)
        output += '  };\n}\n\n\n'
        output += '#endif//__GUARD_%s_HPP__\n' % className.upper()
        with open(className + '.hpp', 'wb') as file:
            file.write(output.encode('utf-8'))
            file.flush()
        
        voidIt = '    (void) original;'
        numericals = ['char', 'byte', 'short', 'int', 'long', 'size_t', 'long long', 'float', 'long float', 'double']
        numericals = ['signed ' + t for t in numericals] + ['unsigned ' + t for t in numericals] + numericals
        (varInit, varCopy, varMove, varFree, classCopy, classMove) = ([], [], [], [], [], [])
        for varLine in varLines:
            varLine = varLine[:varLine.index(';')].strip()
            space = 0
            for superClass in supers:
                classCopy.append('%s::__copy__((%s&)*this, (%s&)original);' % (superClass, superClass, superClass))
                classMove.append('//std::move((%s&)*this, (%s&)original);' % (superClass, superClass))
            for s in range(0, len(varLine)):
                if varLine[s] == ' ':
                    space = s
            varType = varLine[:space]
            varName = varLine[space + 1:]
            if varType == 'bool':
                varInit.append('this->' + varName + ' = false;')
            elif varType in numericals:
                varInit.append('this->' + varName + ' = 0;')
            else:
                varInit.append('this->' + varName + ' = nullptr;')
            varCopy.append('this->%s = original.%s;' % (varName, varName))
            if (varType == 'bool') or (varType in numericals):
                varMove.append('//std::swap(this->%s, original.%s);' % (varName, varName))
            else:
                varMove.append('//std::move(this->%s, original.%s);' % (varName, varName))
            if (varType != 'bool') and (varType not in numericals):
                varFree.append('delete %s;' % varName)
        varInit = '\n'.join(['    //' + item for item in (['//TO' + 'DO implement constructor'] + varInit)])
        varCopy = '\n'.join(['    //' + item for item in varCopy])
        varMove = '\n'.join(['    //' + item for item in varMove])
        varFree = '\n'.join(['    //' + item for item in (['//TO' + 'DO implement destructor'] + varFree)])
        classCopy = '\n'.join(['    //' + item for item in classCopy])
        classMove = '\n'.join(['    //' + item for item in classMove])
        output = '// -*- mode: c++, coding: utf-8 -*-\n%s\n#include "%s.hpp"\n' % (copyNotice, className)
        output += '\n\n/**\n * Text based roll playing game\n * \n * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n * \n * @author  Mattias Andrée <maandree@kth.se>\n */\n'
        output += 'namespace tbrpg\n{\n'
        output += '  /**\n   * Constructor\n   */\n  %s::%s()%s\n  {\n%s\n  }\n  \n' % (className, className, superDefault, varInit)
        output += '  /**\n   * Copy constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(const %s& original)%s\n  {\n%s\n%s\n  }\n  \n' % (className, className, className, superCopy, voidIt, varCopy)
        output += '  /**\n   * Copy constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(%s& original)%s\n  {\n%s\n%s\n  }\n  \n' % (className, className, className, superCopy, voidIt, varCopy)
        output += '  /**\n   * Move constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(%s&& original)%s\n  {\n%s\n%s\n  }\n  \n  \n  \n' % (className, className, className, superCopy, voidIt, varMove)
        output += '  /**\n   * Destructor\n   */\n'
        output += '  %s::~%s()\n  {\n%s\n  }\n  \n  \n  \n' % (className, className, varFree)
        output += '  /**\n   * Assignment operator\n   * \n   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(const %s& original)\n  {\n' % (className, className, className)
        output += '%s\n%s\n    return *this;\n  }\n  \n' % (voidIt, classCopy + varCopy)
        output += '  /**\n   * Assignment operator\n   * \n   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(%s& original)\n  {\n' % (className, className, className)
        output += '%s\n%s\n    return *this;\n  }\n  \n' % (voidIt, classCopy + varCopy)
        output += '  /**\n   * Move operator\n   * \n   * @param   original  The moved object, '
        output += 'its resourced will be moved\n   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(%s&& original)\n  {\n' % (className, className, className)
        output += '%s\n%s\n    return *this;\n  }\n  \n' % (voidIt, classMove + varMove)
        output += '  /**\n   * Copy method\n   * \n'
        output += '   * @param  self      The object to modify\n   * @param  original  The reference object\n'
        output += '   */\n  void %s::__copy__(%s& self, const %s& original)\n' % (className, className, className)
        output += '  {\n    self = original;\n  }\n'
        output += '  \n}\n\n'
        with open(className + '.cc', 'wb') as file:
            file.write(output.encode('utf-8'))
            file.flush()
        
        classLine = line
        varLines = []

