#!/usr/bin/python3

n, q = map(int, input().split())
a = list(map(int, input().split()))
for i in range(q):
    t, l, r = map(int, input().split())
    if t == 1:
        ans = 0
        for j in range(l, r+1):
            ans += a[j]
        print(ans)
    else:
        a[l] = r
