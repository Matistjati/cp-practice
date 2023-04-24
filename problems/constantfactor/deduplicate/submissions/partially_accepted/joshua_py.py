#!/usr/bin/env python3

mod = 1 << 20
q = int(input())
for _ in range(q):
    k,a,c,m,n = [int(i) for i in input().split()]
    m = 1 << m
    seen = set()
    seen.add(k)
    for i in range(n):
        k = (k*a+c)%m
        seen.add(k)
    print(len(seen))