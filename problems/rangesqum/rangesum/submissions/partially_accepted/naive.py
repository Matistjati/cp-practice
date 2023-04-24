#!/usr/bin/python3

n, q = map(int, input().split())
a = list(map(int, input().split()))
for i in range(q):
    l, r = map(int, input().split())
    ans = 0
    for j in range(l, r+1):
        ans += a[j]
    print(ans)
