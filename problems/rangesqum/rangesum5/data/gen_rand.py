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

n=int(cmdlinearg("n", int(2e5)))
q=int(2e5)

print(n,q)
if mode=="random":
    for i in range(q):
        T = randint(0, 1)

        if T==0:
            l = randint(0, n-2)
            r = randint(l, n-1)
            print(T,l,r)
        else:
            l = randint(0, n-2)
            r = randint(l, n-1)
            print(T, l, r, randint(1,int(1e9)))

elif mode=="worstcase":
    
    for i in range(q):
        T = randint(0, 1)

        if T==0:
            l = randint(0, n-2)
            r = randint(l, n-1)
            print(T,l,r)
        else:
            l = randint(0, randint(1,10))
            r = randint(n-randint(5,20), n-1)
            print(T, l, r, randint(1,int(1e9)))
        
else:
    print("ERROR")
