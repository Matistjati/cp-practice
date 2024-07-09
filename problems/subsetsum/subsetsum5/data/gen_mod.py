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

items = [(random.randint(2,3)*random.randint(0, 50))%v for i in range(n)]
print(n)
print(" ".join(str(i) for i in items))
