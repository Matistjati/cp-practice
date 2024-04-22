#!/usr/bin/python3

import math
import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

def gen_tree(mode,n):
    eds = []
    depth = [0]
    if mode== 'line':
        for i in range(0,n-1):
            eds.append((i,i+1))
    else:
        deg = [0 for i in range(n)]
        for i in range(1, n):
            while True:
                if mode == 'random':
                    pred = random.randrange(i)
                elif mode == 'deep':
                    pred = i-1 - int(random.uniform(0, i**0.1) ** 10)
                elif mode == 'deeper':
                    if i < 4:
                        pred = random.randrange(i)
                    else:
                        hi = math.log2(math.log2(i))
                        pred = i - int(2 ** 2 ** min(random.uniform(-3, hi), random.uniform(-3, hi), random.uniform(-3, hi)))
                else:
                    assert False, f"unknown mode {mode}"
                assert 0 <= pred < i
                if deg[pred] < 3:
                    break
            deg[pred]+=1
            deg[i]+=1
            eds.append((pred, i))
            depth.append(depth[pred] + 1)
    return eds

modeTree=cmdlinearg('modeTree')
n=int(2e5)
q=n
random.seed(int(cmdlinearg('seed', sys.argv[-1])))
eds = gen_tree(modeTree,n)
print(n,q)
for a,b in eds:
    print(a,b)


from random import randint as rand
for i in range(q):
    print(rand(0,n-1), rand(0,n-1))