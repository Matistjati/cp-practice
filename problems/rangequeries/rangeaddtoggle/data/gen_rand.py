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

n = int(4e5)
q = n

print(n,q)


for i in range(q):
    t = randint(1,3)
    if t==1:
        print(t,randint(0,n-1))
    if t==2:
        l = randint(0, n-2)
        r = randint(l, n-1)
        print(t,l,r,randint(1,int(1e7)))
    if t==3:
        print(t,randint(0,n-1))
