from collections import defaultdict

n = int(input())
x = int(input())

coins = sorted([int(x) for x in input().split()])
memo = defaultdict(int)
def dfs(i, j):
    if i == x:
        return 1
    if i > x:
        return 0
    if (i, j) in memo:
        return memo[(i, j)]

    ret = dfs(i + coins[j], j)
    if j + 1 < n:
        ret += dfs(i, j + 1)
    memo[(i, j)] = ret
    return ret

print(dfs(0, 0))
