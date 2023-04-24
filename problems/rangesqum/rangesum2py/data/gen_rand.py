#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
q = int(cmdlinearg('q'))
t = int(cmdlinearg('t', 0))
print(n,q)
print(" ".join(str(random.randint(1, int(1e9))) for i in range(n)))
for i in range(q):
    T = random.randint(1, 2)
    if t and random.randint(0,1):
        T = 1
    if T == 1:
        l = random.randint(0, n-1)
        r = random.randint(0, n-1)
        if l > r:
            l, r = r, l
        if t:
            l = random.randint(0, l)
            r = random.randint(r, n-1)
        print(T, l, r)
    else:
        x = random.randint(0, n-1)
        y = random.randint(1, int(1e9))
        print(T, x, y)
