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
from subprocess import Popen
from threading import Thread, Lock, Condition


nodes = int(input())
pairs = []

while True:
    try:
        line = input()
        if line is None:
            break
    except:
        break
    pairs.append(line.split(' '))

deps = {}
for pair in pairs:
    if pair[0] in deps:
        deps[pair[0]].append(pair[1])
    else:
        deps[pair[0]] = [pair[1]]

for file in os.listdir('./src/'):
    if os.path.isfile('./src/' + file):
        if file.endswith('.hpp') and not file.startswith('.'):
            file = file[:-4]
            if file not in deps:
                deps[file] = []

modified = True
while modified:
    modified = False
    for file in deps:
        for dep in deps[file]:
            additionals = deps[dep]
            for additional in additionals:
                if (additional != file) and (additional not in deps[file]):
                   deps[file].append(additional)
                   modified = True

queue = []

_deps = {}
for file in deps:
    if file in deps[file]:
        del deps[file][deps[file].index(file)]
    _deps[file] = [item for item in deps[file]]
while len(_deps) > 0:
    count = len(_deps)
    for file in _deps:
        if _deps[file] == 0:
            queue.append(file)
            del _deps[file]
    if count == len(_deps):
        bestfile = list(_deps.keys())[0]
        bestcount = len(_deps[list(_deps.keys())[0]])
        for file in _deps:
            if len(_deps[file]) < bestcount:
                bestcount = len(_deps[file])
                bestfile = file
        queue.append(bestfile)
        del _deps[bestfile]

success = True
readmutex = Lock()
threadmap = [None] * nodes
threads = []

class MakeThread(Thread):
    def __init__(self, index):
        Thread.__init__(self)
        self.monitor = Condition()
        self.index = index
    
    def run(self):
        file = None
        ev = 0
        while True:
            try:
                readmutex.acquire()
                if len(queue) == 0:
                    readmutex.release()
                    break
                file = queue[0]
                queue[:] = queue[1:]
                for dep in deps[file]:
                    if dep in threadmap:
                        i = threadmap.index(dep)
                        print('\033[01;33mWaiting for ' + dep + '@' + str(i) + ' [' + str(self.index) + ']\033[21;39m')
                        m = threads[i].monitor
                        m.acquire()
                        readmutex.release()
                        m.wait()
                        readmutex.acquire()
                        m.release()
                threadmap[self.index] = file
                print('\033[01;34mCompiling ' + file + ' [' + str(self.index) + ']\033[21;39m')
                readmutex.release()
                ev = self.compile(file)
            except:
                readmutex.acquire()
                success = False
                print('\033[01;31mFailed! with ' + file + ', returned ' + str(ev) + ' [' + str(self.index) + ']\033[21;39m')
            else:
                readmutex.acquire()
                if ev == 0:
                    print('\033[01;32mDone ' + file + ' [' + str(self.index) + ']\033[21;39m')
                else:
                    success = False
                    print('\033[01;31mFailed with ' + file + ', returned ' + str(ev) + ' [' + str(self.index) + ']\033[21;39m')
                threadmap[self.index] = None
            readmutex.release()
            self.monitor.acquire()
            self.monitor.notify_all()
            self.monitor.release()
    
    def compile(self, file):
        return Popen(['make', file + '.o'], stdin=sys.stdin, stdout=sys.stdout, stderr=sys.stderr).wait()

for i in range(0, nodes):
    thread = MakeThread(i)
    threads.append(thread)
    thread.start()

for i in range(0, nodes):
    threads[i].join()

exit(0 if success else 1)

