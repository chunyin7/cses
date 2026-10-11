inputs = input().split() # n, m, k
n = int(inputs[0])
m = int(inputs[1])
k = int(inputs[2])
applicants = sorted([int(s) for s in input().split()])
apartments = sorted([int(s) for s in input().split()])

ret = 0
l = 0
for a in applicants:
    while l < m and apartments[l] < a - k:
        l += 1
    if l >= m:
        break
    if apartments[l] <= a + k:
        ret += 1
        l += 1
     
print(ret)
