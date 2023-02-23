n = int(input())
lst = [2 ** i for i in range(0, int(n ** 0.5) + 1)]
mod = 1000000000
dp = [0 for _ in range(n + 1)]
dp[0] = 1
for i in lst:
    for j in range(i, n + 1):
        if j - i >= 0:
            dp[j] += dp[j - i] % mod
print(dp[n])
