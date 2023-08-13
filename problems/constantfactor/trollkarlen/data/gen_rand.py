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
n = int(cmdlinearg("n"))
maxv = int(cmdlinearg("n", int(1e9)))

print(n)
if mode=="random":
    tight = int(cmdlinearg("tight"))
    lo = int(maxv/tight)

    for i in range(n):
        if randint(0,1):
            print(1, randint(lo, maxv), randint(1, maxv))
        else:
            print(2, randint(lo, maxv), randint(1, maxv))
elif mode=="long":
    lo = int(maxv*0.95)
    print(1, 420, int(maxv/3))
    head = 420
    i = 0
    while i < n-1:
        if randint(0,10)==0:
            if i == n-2: continue
            nextv = randint(lo, maxv)
            print(1, nextv, randint(1, maxv))
            print(2, nextv, head)
            i+=2
        else:
            nextv = randint(lo,maxv)
            print(2, head, nextv)
            head = nextv
            i+=1
        
        