#!/usr/bin/python3

n=int(input())

a=[*map(int,input().split())]
a.sort()

h=sum(a)


if n>4000:
    print(h+1)
    exit()
"""
#Attempt 1 with n*h array
allNums=[0]*(h+1)

allNums[0]=1


#testar utan bitset/bitmask
for x in a:
    for i in range(h-1,-1,-1):
        #print(allNums[i],i)
        if allNums[i]:
            allNums[i+x]=1
    #print(allNums)
print(sum(allNums))
"""

"""
Attempt 2 with set
visited=set()
visited.add(0)

for x in a:
    new=set()
    for v in visited:
        if v+x not in visited:
            new.add(v+x)
    for v in new:
        visited.add(v)

print(len(visited))
"""



#Attempt 3: using normal int and bitmask
temp=1
for x in a:
    temp|=temp<<x

    
#print(temp.bit_count())    
print(bin(temp).count("1"))
"""
BIT_COUNT = [0] * 2**11
for i in range(len(BIT_COUNT)):
  BIT_COUNT[i] = BIT_COUNT[i // 2] + (i & 1)

def count_bits(temp):
  nhalf = temp.bit_length() // 2
  if nhalf <= 5:
      return BIT_COUNT[temp]
  x = temp >> nhalf 
  y = temp ^ (x << nhalf)
  return count_bits(x) + count_bits(y)
"""
#print(count_bits(temp))