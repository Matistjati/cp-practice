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
mode = cmdlinearg("mode", "random")
n,q = int(2e5),int(2e5)

print(n,q)


print(" ".join(str(randint(1,int(1e4))) for i in range(n)))

if mode=="random":
    for i in range(q):
        l = randint(0, n-2)
        r = randint(l, n-1)
        print(l,r,randint(1,int(1e4)))
elif mode=="worst":
    for i in range(q):
        l = 0
        r = randint(n-10, n-1)
        print(l,r,randint(1,int(1e4)))
else:
    print("ERROR")