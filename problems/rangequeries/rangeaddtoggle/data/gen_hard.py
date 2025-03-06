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
balance_add = int(cmdlinearg("weight_add"))

print(n,q)

touched = []
for i in range(q):
    if randint(0, 20)==0 and len(touched):
        print(1, random.choice(touched))
    elif randint(0,10)>balance_add:
        l = randint(0, 2*int(math.sqrt(n)))
        r = randint(n-2*int(math.sqrt(n)), n-1)
        print(2,l,r,randint(1,int(1e7)))
    else:
        i = randint(0,n-1)
        touched.append(i)
        print(3,i)
