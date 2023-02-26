s = []
for _ in range(3):
    s.append(input())
dp = [[0 for _ in range(101)] for _ in range(101)]
ans = 0


def maxLCS(x, y):
    tmp = 0
    for i in range(x):
        for j in range(y):
            tmp = max(tmp, dp[i][j])
    return tmp


for i in range(len(s[0])):
    for j in range(len(s[1])-1, -1, -1):
        if s[0][i] == s[1][j]:
            for k in range(len(s[2])-1, -1, -1):
                dp[j][k] = max(dp[j][k], dp[j][k-1], dp[j-1][k])
                if s[1][j] == s[2][k]:
                    dp[j][k] = max(dp[j][k], maxLCS(j, k)+1)
                    ans = max(ans, dp[j][k])

print(ans)