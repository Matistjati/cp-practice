#!/usr/bin/python3

n, q = map(int, input().split())

a = list(map(int, input().split()))

m = 300
b = [0] * ((n + m - 1) // m)
for i in range(n):
    b[i // m] += a[i]

for i in range(q):
    t, l, r = map(int, input().split())
    if t == 1:
        ans = 0
        j = l
        while j <= r:
            if j % m == 0 and j + m - 1 <= r:
                ans += b[j // m]
                j += m
            else:
                ans += a[j]
                j += 1
        print(ans)
    else:
        b[l // m] += r - a[l]
        a[l] = r
