#공통부분 문자열 눈알빠져요.
import sys
input = sys.stdin.readline

str1 = input().rstrip()
str2 = input().rstrip()

result = 0
dp = [[0] * (len(str2) + 1) for _ in range(len(str1) + 1)]

for i in range(1, len(str1) + 1) :
	for j in range(1, len(str2) + 1) :
		if str1[i - 1] == str2[j - 1] :
			dp[i][j] = dp[i - 1][j - 1] + 1
			result = max(dp[i][j], result)

print(result)