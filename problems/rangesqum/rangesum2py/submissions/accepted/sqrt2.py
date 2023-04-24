#!/usr/bin/python3


n, q = map(int, input().split())
a = list(map(int, input().split()))

def build_b():
    b = [0]
    for i in range(n):
        b.append(b[i] + a[i])
    return b

b = build_b()
nq = []

for i in range(q):
    t, l, r = map(int, input().split())
    if t == 1:
        ans = b[r+1] - b[l]
        for x, y in nq:
            if l <= x <= r:
                ans += y
        print(ans)
    else:
        nq.append((l, r - a[l]))
        a[l] = r
    
    if len(nq) > 200:
        b = build_b()
        nq = []
