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
n = int(1e5)
q = n
print(n,q)

for i in range(n-1):
    print(i+1, randint(0, i))

for i in range(q):
    d = 0
    while randint(0,1):
        d = (d+randint(0,1))*2
    print(randint(0,n-1), d)