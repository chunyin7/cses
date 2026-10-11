inputs = input().split()
n = int(inputs[0])
x = int(inputs[1])
weights = sorted([int(x) for x in input().split()])
ret = 0
l, r = 0, n - 1
while l <= r:
    if l != r and weights[l] + weights[r] <= x:
        ret += 1
        l += 1
        r -= 1
    else:
        ret += 1
        r -= 1

print(ret)
