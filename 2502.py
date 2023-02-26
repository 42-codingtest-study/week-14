D, K = map(int, input().split())

dp = [0 for i in range(D)]
dp[0] = 1
dp[1] = 1

while True:
	for i in range(2, D):
		dp[i] = dp[i-1] + dp[i-2]

	if dp[D-1] == K:
		print(dp[0])
		print(dp[1])
		break
	elif dp[D-1] > K:
		dp[0] += 1
		dp[1] = dp[0]
	else:
		dp[1] += 1