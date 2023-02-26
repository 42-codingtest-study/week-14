import sys
input = sys.stdin.readline

def solution(N, graph):
	dp = [[0] * 3 for _ in range (N)]
	dp[1][0] = graph[1][0] + graph[0][1]
	dp[1][1] = graph[1][1] + min(dp[1][0], graph[0][1], graph[0][2]+graph[0][1])
	dp[1][2] = graph[1][2] + min(dp[1][1], graph[0][1], graph[0][1] + graph[0][2])

	for i in range(2, N) :
		for j in range(3) :
			if j == 0:
				min_value = min(dp[i - 1][j], dp[i - 1][j + 1])
			elif j == 1:
				min_value = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1], dp[i][j - 1])
			else:
				min_value = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
			dp[i][j] = min_value + graph[i][j]

	print(dp[-1][1])

testcase = 0
N = int(input())
while N != 0:
    testcase += 1
    graph = [list(map(int, input().split())) for _ in range(N)]
    print(testcase, end='. ')
    solution(N, graph)
    N = int(input())