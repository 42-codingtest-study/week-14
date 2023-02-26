# 1, 2, 3 더하기 7
# https://www.acmicpc.net/problem/15992

dp = [[0] * 1001 for _ in range(1001)]
mod = 1000000009
dp[1][1] = dp[2][1] = dp[3][1] = 1
for i in range(2, 1001) :
    for j in range(1, 1001) :
        for k in range(1, 4) :
            if j - k > 0 :
                dp[j][i] += dp[j - k][i - 1]
            dp[j][i] %= mod
for _ in range(int(input())) :
    n, m = map(int, input().split())
    print(dp[n][m])
