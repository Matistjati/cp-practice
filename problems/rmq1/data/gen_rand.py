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
print(n,q)
print(" ".join(str(random.randint(0, int(1e9))) for i in range(n)))
for i in range(q):
    l = random.randint(0,n-1)
    r = random.randint(l, n-1)
    print(l, r)