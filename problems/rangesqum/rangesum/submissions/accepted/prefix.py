#!/usr/bin/python3

n, q = map(int, input().split())
a = list(map(int, input().split()))
b = [0]
for i in range(n):
    b.append(b[i] + a[i])
for i in range(q):
    l, r = map(int, input().split())
    print(b[r+1] - b[l])
