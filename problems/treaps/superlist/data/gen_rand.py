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
q = int(cmdlinearg('q'))
a = int(cmdlinearg("i"))
b = int(cmdlinearg("e"))
c = int(cmdlinearg("p"))
choices = [0,1,2]
queries = random.choices(choices, weights=[a,b,c], k=q)
print(q)
s = 0
for t in queries:
    if t==0 or s==0:
        print(0, random.randint(0, s), random.randint(1, int(1e9)))
        s += 1
    elif t==1:
        print(1, random.randint(0, s-1))
        s -= 1
    elif t==2:
        print(2, random.randint(0, s-1))