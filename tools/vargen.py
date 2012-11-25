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
lines = lines[lineptr:] + ['EOF']
lineptr = 0

classLine = None
varLines = None

for line in lines:
    if len(line) == 0:
        continue
    if line[0] == '\t':
        varLines.append(line[1:])
    elif classLine is None:
        classLine = line
        varLines = []
    else:
        classLine = line
        classComment = classLine[classLine.index(';') + 1:].strip()
        classLine = classLine[:classLine.index(';')].strip()
        className = classLine
        if ':' in className:
            className = className[:className.index(':')]
        
        output = '// -*- mode: c++, coding: utf-8 -*-\n' + copyNotice + '\n'
        output += '#ifndef __%s__\n' % className.upper()
        output += '#define __%s__\n' % className.upper()
        output += '\n\n#include <stdlib.h>\n#include <algorithm>\n\n/**\n'
        output += ' * Text based roll playing game\n * \n * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n * \n * @author  Mattias Andrée <maandree@kth.se>\n */\n'
        output += 'namespace tbrpg\n{\n'
        output += '  /**\n   * %s\n   */\n  class %s\n  {\n  public:\n' % (classComment, classLine)
        for varLine in varLines:
            varComment = varLine[varLine.index(';') + 1:].strip()
            varLine = varLine[:varLine.index(';')].strip()
            output += '    /**\n     * %s\n     */\n    %s\n\n' % (varComment, varLine)
        output += '\n\n    /**\n     * Construction\n     */\n    %s();\n\n' % className
        output += '    /**\n     * Copy constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(const %s& original);\n\n' % (className, className)
        output += '    /**\n     * Copy constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(%s& original);\n\n' % (className, className)
        output += '    /**\n     * Move constructor\n     * \n     * @param  original  The object to clone\n'
        output += '     */\n    %s(%s&& original);\n\n\n\n' % (className, className)
        output += '    /**\n     * Destructor\n     */\n    virtual ~%s();\n\n\n\n' % className
        output += '    /**\n     * Assignment operator\n     * \n     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */    virtual %s& operator =(const %s& original);\n\n' % (className, className)
        output += '    /**\n     * Assignment operator\n     * \n     * @param   original  The reference object\n'
        output += '     * @return            The invoked object\n'
        output += '     */    virtual %s& operator =(%s& original);\n\n' % (className, className)
        output += '    /**\n     * Move operator\n     * \n     * @param   original  The moved object, '
        output += 'its resourced will be moved\n     * @return            The invoked object\n'
        output += '     */    virtual %s& operator =(%s&& original);\n\n' % (className, className)
        output += '  };\n'
        output += '}\n\n\n'
        output += '#endif//__%s__\n' % className.upper()
        with open(className + '.hpp', 'wb') as file:
            file.write(output.encode('utf-8'))
            file.flush()
        
        numericals = ['char', 'byte', 'short', 'int', 'long', 'size_t', 'long long']
        numericals = ['signed ' + t for t in numbericals] + ['unsigned ' + t for t in numbericals]
        (varInit, varCopy, varMove, varFree) = ([], [], [], [])
        for varLine in varLines:
            varLine = varLine[:varLine.index(';')].strip()
            space = 0
            for s in range(0, len(varLine)):
                if varLine[s] == ' ':
                    space = s
            varType = varLine[:s]
            varName = varLine[s + 1:]
            if varType == 'bool':
                varInit.append(varName + ' = false;')
            elif varType in numericals:
                varInit.append(varName + ' = 0;')
            else:
                varInit.append(varName + ' = nullptr;')
            varCopy.append('this->%s = original.%s;' % (varName, varName))
            if (varType == 'bool') or (varType in numbericals):
                varMove.append('std::swap(this->%s, original.%s);' % (varName, varName))
            else:
                varMove.append('std::move(this->%s, original.%s);' % (varName, varName))
            if (varType != 'bool') and (varType not in numbericals):
                varFree.append('delete %s;' % varName)
        varInit = '\n'.join(['    //' + item for item in (['TODO implement constructor'] + varInit)])
        varCopy = '\n'.join(['    ' + item for item in varCopy])
        varMove = '\n'.join(['    ' + item for item in varMove])
        varFree = '\n'.join(['    //' + item for item in (['TODO implement destructor'] + varFree)])
        output = '// -*- mode: c++, coding: utf-8 -*-\n%s\n#include "%s.hpp"\n' % (copyNotice, className)
        output += '\n\n/**\n * Text based roll playing game\n * \n * DD2387 Program construction with C++\n'
        output += ' * Laboration 3\n * \n * @author  Mattias Andrée <maandree@kth.se>\n */\n'
        output += 'namespace tbrpg\n{\n'
        output += '  /**\n   * Constructor\n   */\n  %s::%s()\n  {\n%s\n  }\n\n' % (className, className, varInit)
        output += '  /**\n   * Copy constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(const %s& original)\n  {\n%s\n  }\n\n' % (className, className, className, varCopy)
        output += '  /**\n   * Copy constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(%s& original)\n  {\n%s\n  }\n\n' % (className, className, className, varCopy)
        output += '  /**\n   * Move constructor\n   * \n   * @param  original  The object to clone\n   */\n'
        output += '  %s::%s(%s&& original)\n  {\n%s\n  }\n\n\n\n' % (className, className, className, varMove)
        output += '  /**\n   * Destructor\n   */\n'
        output += '  %s::~%s()\n  {\n%s\n  }\n\n\n\n' % (className, className, className, varFree)
        output += '    /**\n   * Assignment operator\n   * \n   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(const %s& original)\n  {\n' % (className, className, className)
        output += '%s\n    return *this;\n  }\n\n' % varCopy
        output += '    /**\n   * Assignment operator\n   * \n   * @param   original  The reference object\n'
        output += '   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(%s& original)\n  {\n' % (className, className, className)
        output += '%s\n    return *this;\n  }\n\n' % varCopy
        output += '    /**\n   * Move operator\n   * \n   * @param   original  The moved object, '
        output += 'its resourced will be moved\n   * @return            The invoked object\n   */'
        output += '\n  %s& %s::operator =(%s&& original)\n  {\n' % (className, className, className)
        output += '%s\n    return *this;\n  }\n\n' % varMove
        output += '}\n\n'
        with open(className + '.cc', 'wb') as file:
            file.write(output.encode('utf-8'))
            file.flush()
        
        classLine = line
        varLines = []

