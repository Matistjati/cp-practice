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
exclude = int(cmdlinearg("exclude"))

n=int(cmdlinearg("n", int(2e5)))
q=int(2e5)


print(n,q)
if mode=="random":
    print(" ".join(str(random.randint(0, int(1e8))) for i in range(n)))
    for i in range(q):
        T = randint(1, 3)
        while T==exclude:
            T = randint(1, 3)

        l = randint(0, n-1)
        r = randint(l, n-1)
        if T==1:
            print(T,l,r, randint(0, int(1e8)))
        elif T==2:
            print(T, l, r, randint(0, int(1e8)))
        else:
            print(T,l,r)

elif mode=="large_interval":
    
    print(" ".join(str(random.randint(0, int(1e8))) for i in range(n)))
    for i in range(q):
        T = randint(1, 3)
        while T==exclude:
            T = randint(1, 3)

        l = randint(0, 1000)
        r = randint(n-1-randint(0, 1000), n-1)
        if T==1:
            print(T,l,r, randint(0, int(1e8)))
        elif T==2:
            print(T, l, r, randint(0, int(1e8)))
        else:
            print(T,l,r)
elif mode=="worst_case":
    nums = [i for i in range(n)]
    i = 0
    while i < n:
        nums[i]=int(1e8)
        i+=1
    print(*nums)
    k = n
    for i in range(q):
        T = randint(1, 3)
        while T==exclude:
            T = randint(1, 3)

        l = randint(0, n-1)
        r = randint(l, n-1)
        if T==1:
            print(T, 0, n-1, k)
            k-=2
        elif T==2:
            print(T, l, r, randint(0, int(1e8)))
        else:
            print(T, l, r)
else:
    print("ERROR")
