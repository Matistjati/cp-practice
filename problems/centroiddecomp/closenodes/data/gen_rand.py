import sys
import random
from random import randint, seed

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(2e5)
q = n
print(n,q)

for i in range(n-1):
    print(i+1, randint(0, i))

colorenable = [i+1 for i in range(n-1)] # never enable 0
random.shuffle(colorenable)

for i in range(q):
    if randint(1,10)==1:
        print(0, colorenable[-1])
        del colorenable[-1]
    else:
        print(1, randint(0,n-1))