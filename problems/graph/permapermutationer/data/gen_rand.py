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



edges=set()

def randomedge(lo=0, hi=1e5):
    while 1:
        a=randint(1,n-1)
        b=randint(a+1,n)
        if (a,b) in edges:
            continue
        
        edges.add((a,b))
        print(a,b,randint(lo, hi))
        return

if mode=="random":
    n=randint(2,int(1e6))
    m=randint(2,min(int(1e6),int(n*(n-1)/2)-10))
    print(n,m)
    for i in range(m):
        randomedge()
elif mode=="worstcase":
    n=1400
    m=0
    for i in range(n-2):
        m+=1
    m+=1
    for i in range(n):
        for j in range(i+1,n-1):
            m+=1
    print(n,m)
    for i in range(n-2):
        print(i+1,i+2,1)
    print(n-1,n,int(4e6))
    for i in range(n):
        for j in range(i+1,n-1):
            print(i+1,j+1,int(2e6)+i+j)
        
        