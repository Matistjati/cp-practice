from random import randint as rand

n=500

nums = [0 for i in range(n+1)]
b=rand(1, int(1e12))
nums[499]=b
nums[500]=500
t = (b+1)*499
print(n,t)
print(*nums)