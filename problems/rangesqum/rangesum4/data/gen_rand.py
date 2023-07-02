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
mode = cmdlinearg("mode")

n=int(1e5)
q=n

print(n,q)
if mode=="random":
    for i in range(q):
        T = randint(0, 1)

        if T==0:
            l = randint(0, n-2)
            r = randint(l, n-1)
            print(T,l,r)
        elif T==1:
            print(T, randint(0,n-1),randint(1,int(1e9)))
        else:
            l = randint(0, n-2)
            r = randint(l, n-1)
            print(T, l, r, randint(1,int(1e9)))

elif mode=="worstcase":
    for i in range(q-60):
        print(1, i, int(1e9)-randint(1, 100))
    
    k=int(1e9)-100
    for i in range(30):
        l = randint(0, n-2)
        r = randint(l, n-1)
        print(0, l, r)
        print(2, 0, n-1, k)
        k %= k//2+1
        if k==0:
            k=1
else:
    print("ERROR")
