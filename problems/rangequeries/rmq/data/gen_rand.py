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

n,q = int(4e5),int(4e5)

print(n,q)


print(" ".join(str(randint(1,int(4e5))) for i in range(n)))

for i in range(q):
    l = randint(0, n-2)
    r = randint(l, n-1)
    print(l,r)
