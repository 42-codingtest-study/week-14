#똑똑한 근일 선생님의 1,2,3 더하기 7
import sys
input = sys.stdin.readline

n = int(input())
num = []
m = 0

for _ in range(n):
    a, b = map(int, input().split())
    num.append([a, b])
    m = max(a, m)

dp = [[0 for _ in range(m + 1)] for _ in range(m + 1)]
dp[1][1] = 1

if m > 1:
    dp[2][1] = 1
    dp[2][2] = 1

if m > 2:
    dp[3][1] = 1
    dp[3][2] = 2
    dp[3][3] = 1

for i in range(4, m + 1):
    for j in range(1, i + 1):
        dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % 1000000009

for a, b in num:
    print(dp[a][b])