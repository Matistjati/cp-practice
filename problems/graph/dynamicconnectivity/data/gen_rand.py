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

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        self.parent[self.find(b)] = self.find(a)

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
mode = cmdlinearg("mode", "random")

n,q=int(1e5),int(2e5)

print(n,q)

uf = UnionFind(n)

if mode=="random":
    edges = set()
    i = 0
    while i < q:
        i+=1
        t = randint(0,2)
        if t==0:
            while 1:
                a,b=randint(0,n-1),randint(0,n-1)
                if a==b:
                    continue
                if a>b:
                    a,b=b,a
                if (a,b) in edges:
                    continue
                edges.add((a,b))
                print(t,a,b)
                break
        if t==1:
            if len(edges)==0:
                i-=1
                continue
            e = random.choice(tuple(edges))
            edges.remove(e)
            print(t,e[0],e[1])
        if t==2:
            while 1:
                a,b=randint(0,n-1),randint(0,n-1)
                if a==b:
                    continue
                
                print(t,a,b)
                break
elif mode=="worstcase":
    edges = set()
    i = 0
    while i < q//2:
        while 1:
            a,b=randint(0,n-1),randint(0,n-1)
            if a==b:
                continue
            if a>b:
                a,b=b,a
            if (a,b) in edges:
                continue
            if uf.find(a)==uf.find(b):
                continue
            edges.add((a,b))
            print(0,a,b)
            break
        i+=1
    
    edges = list(edges)
    j = 0
    while i < q:
        i+=1
        t = randint(1,2)
        if t==1:
            e = edges[j]
            j+=1
            print(t,e[0],e[1])
        if t==2:
            while 1:
                a,b=randint(0,n-1),randint(0,n-1)
                if a==b:
                    continue
                
                print(t,a,b)
                break
        
        