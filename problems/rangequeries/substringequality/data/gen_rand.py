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
mode=cmdlinearg("mode")
noupdates=int(cmdlinearg("noupdates", 0))
n=int(1e5)
q=int(1e5)

if mode=="random":
    print("".join(chr(randint(ord('a'),ord('z'))) for i in range(n)))
    print(q)
    for i in range(q):
        t=randint(0,1)
        if t==0 or noupdates:
            l = randint(0, n-2)
            r = randint(l, n-1)
            v = randint(0, n-2)
            h = randint(v, n-1)
            print(0,l,r,v,h)
        else:
            print(1,randint(0,n-1),chr(randint(ord('a'),ord('z'))))
elif mode=="manyYes":
    print("a"*n)
    print(q)
    for i in range(q):
        print(0,0,n-2,1,n-1)
else:
    print("LIGMA")