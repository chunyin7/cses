from collections import defaultdict

n = int(input())
nums = input().split()

d = defaultdict(int)

for num in nums:
    d[num] += 1

print(len(d)) 
