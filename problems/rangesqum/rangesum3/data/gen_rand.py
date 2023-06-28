#!/usr/bin/python3

import sys
import random
from random import randint
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
nolazy = int(cmdlinearg('nolazy', 0))
hi = int(cmdlinearg("hi", int(1e9-1)))
tinyquery = int(cmdlinearg("tinyquery", 0))
tinyupdate = int(cmdlinearg("tinyupdate", 0))

q = randint(0, int(1e5))
print(q)

for i in range(q):
    T = randint(0, 1)
    l = randint(0, hi-1)
    r = randint(l, hi)

    if tinyupdate and T==1:
        r=l
    if tinyquery and T==0:
        r=l

    if T == 1:
        print(T, l, r, randint(1, int(1e9)))
    else:
        print(T, l, r)
