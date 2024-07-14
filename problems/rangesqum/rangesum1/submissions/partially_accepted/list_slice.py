#!/usr/bin/python3

n, q = [int(i) for i in input().split()]
nums = [int(i) for i in input().split()]

for i in range(q):
    l, r = [int(i) for i in input().split()]
    print(sum(nums[l:r+1]))
