n,q = map(int,input().split())
nums = [0] * n
active = [0] * n


for _ in range(q):
    data = [(int(i)) for i in input().split()]
    t = data[0]
    
    if t == 1:
        i = data[1]
        print(nums[i])
    elif t == 2:
        l = data[1]
        r = data[2]
        v = data[3]
        
        for i in range(l, r + 1):
            if active[i]:
                nums[i] += v
    else:
        i = data[1]
        active[i] ^= 1
    
print(*nums)
    
