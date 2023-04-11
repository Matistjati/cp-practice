#!/usr/bin/python3

class SegTree:
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.sum = 0
        self.left = None
        self.right = None
        if l+1 != r:
            self.left = SegTree(l, (l + r) // 2)
            self.right = SegTree((l + r) // 2, r)
    
    def set(self, i, x):
        if i < self.l or i >= self.r:
            return
        if self.left is None:
            self.sum = x
            return
        self.left.set(i, x)
        self.right.set(i, x)
        self.sum = self.left.sum + self.right.sum
    
    def sm(self, l, r):
        if l <= self.l and r >= self.r:
            return self.sum
        if l >= self.r or r <= self.l:
            return 0
        return self.left.sm(l, r) + self.right.sm(l, r)

n, q = map(int, input().split())

a = list(map(int, input().split()))

st = SegTree(0, n)
for i in range(n):
    st.set(i, a[i])

for i in range(q):
    t, l, r = map(int, input().split())
    if t == 1:
        print(st.sm(l, r + 1))
    else:
        st.set(l, r)
