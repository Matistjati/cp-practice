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
v = int(cmdlinearg('v'))

items = []
while len(items)<n:
    k = random.randint(0, n-len(items))
    v = random.randint(0, 1000)
    for i in range(k):
        items.append(v)
random.shuffle(items)
print(n,random.randint(0,sum(items)))
print(" ".join(str(i) for i in items))