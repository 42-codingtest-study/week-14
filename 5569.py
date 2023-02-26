#출근 경로

w,h = map(int,input().split())
dp = [[[[0] * 2 for _ in range(2)] for _ in range(h)] for _ in range(w)]

for i in range(1,w):
    dp[i][0][0][1] = 1
for i in range(1,h):
    dp[0][i][1][1] = 1
    
	 
for x in range(1,w):
    for y in range(1,h):
        dp[x][y][0][0] = dp[x - 1][y][1][1]
        dp[x][y][0][1] = dp[x - 1][y][0][0] + dp[x - 1][y][0][1]
        dp[x][y][1][0] = dp[x][y - 1][0][1]
        dp[x][y][1][1] = dp[x][y - 1][1][0] + dp[x][y - 1][1][1]

res = sum(dp[w - 1][h - 1][0]) + sum(dp[w - 1][h - 1][1])
print(res % 100000)