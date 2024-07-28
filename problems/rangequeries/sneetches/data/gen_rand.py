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

exclude = int(cmdlinearg("exclude"))
n = int(cmdlinearg("n"))
q = int(2e5)

print(n,q)


mode = cmdlinearg("mode")
if mode=="zigzag":
    print("01"*(n//2))
    if int(cmdlinearg("z")):
        mode="random"
    else:
        mode="large"
else:
    print("".join(random.choice(("0","1")) for i in range(n)))

if mode=="random":
    for i in range(q):
        t = randint(1,2)
        while t==exclude:
            t = randint(1,2)
        l = randint(0, n-1)
        r = randint(l, n-1)
        print(t, l, r)
elif mode=="large":
    for i in range(q):
        t = randint(1,2)
        while t==exclude:
            t = randint(1,2)
        l = randint(0, 1000)
        r = randint(n-1-1000, n-1)
        print(t, l, r)
else:
    print("ERROR")