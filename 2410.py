# 2의 멱수의 합
# https://www.acmicpc.net/problem/2410

n = int(input())
lst = [1 << i for i in range(n + 1)]
mod = 1000000000
dp = [0] * (n + 1)
dp[0] = 1
for i in lst:
    if i <= n :
        for j in range(i, n + 1):
            dp[j] += dp[j - i] % mod
print(dp[n])
