#스티커

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(2)]

    # 2행 DP배열 형성
    dp = [[0] * N for _ in range(2)]

    # 스티커 길이 1
    dp[0][0] = arr[0][0]
    dp[1][0] = arr[1][0]
    if N == 1:
        print(max(dp[0][0], dp[1][0]))
        continue

    # 스티커 길이 2
    dp[0][1] = arr[1][0] + arr[0][1]
    dp[1][1] = arr[0][0] + arr[1][1]
    if N == 2:
        print(max(dp[0][1], dp[1][1]))
        continue

    # 스티커 길이 3
    for i in range(2, N):
        dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + arr[0][i]
        dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + arr[1][i]

    print(max(dp[0][-1], dp[1][-1]))