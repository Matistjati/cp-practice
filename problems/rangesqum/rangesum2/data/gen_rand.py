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
p_query = float(cmdlinearg('p_query'))
mode = cmdlinearg('mode')

print(n,q)
print(*(random.randint(1, 10**9) for i in range(n)))
for i in range(q):
    T = 1 if random.random() < p_query else 2
    if T == 1:
        if mode == "random":
            l = random.randint(0, n-1)
            r = random.randint(0, n-1)
            if l > r:
                l, r = r, l
        elif mode == "wide":
            l = random.randint(0, 2*int(n**0.5))
            r = random.randint(n - 2*int(n**0.5), n-1)
        else:
            assert 0
        print(T, l, r)
    else:
        x = random.randint(0, n-1)
        y = random.randint(1, 10**9)
        print(T, x, y)
