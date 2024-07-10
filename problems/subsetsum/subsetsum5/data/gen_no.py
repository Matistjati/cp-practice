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

n=4000
base = [
    (2,2,3),
    (5,6,7,9),
    (5,7,6)
]

ind = int(cmdlinearg("case"))

n -= len(base[ind])-1

items = [random.randint(0, 450) for i in range(n)]
items += base[ind][:-1]
t = sum(items)+base[ind][-1]
random.shuffle(items)
print(4000, t)
print(*items)
