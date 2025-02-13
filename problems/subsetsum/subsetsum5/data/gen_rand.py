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

items = [random.randint(0,v) for i in range(n)]
t = random.randint(0, min(int(2e6), sum(items)))
print(n, t)
items = [i if i<=t else random.randint(0, t-1) for i in items]
random.shuffle(items)
print(*items)
