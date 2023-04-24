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
q = int(cmdlinearg('q'))
mode = cmdlinearg('mode')


print(q)
for i in range(q):
    m = 19 if randint(0,10)==0 else 20
    hi = (1 << m) - 1

    if mode=="tryhard":
        k0 = 2*randint(0, int(hi/2))+1
        a = 3+8*randint(0, int(hi/9))
    elif mode=="random":
        k0 = randint(0, hi)
        a = randint(0, hi)
    else:
        assert False
    c = randint(0, hi)
    
    print(" ".join(str(i) for i in (k0,a,c,m,int(1e5))))
