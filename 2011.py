# 1 26

# 25114

# 2 5 1 1 4
# 25 11 4
# 25 1 1 4
# 2 5 11 4
# 25 1 14
# 2 5 1 14

# 0 하나만 있을 때

import sys

code = [0] #인덱스 값 0
code += list(sys.stdin.readline())
code.pop()

if code[1] == '0': 
    print(0)
    exit(0)

length = len(code)
dp = [0] * length
dp[0] = 1 
dp[1] = 1

for i in range(2, length):
    first = int(code[i])
    tenth = int(code[i - 1]) * 10 + int(code[i])
    if first > 0: dp[i] += dp[i - 1]
    if tenth >= 10 and tenth <= 26: dp[i] += dp[i - 2]

print(dp[length - 1] % 1000000)

# #1의 자리 수만 가능하다면
# dp[i] += dp[i - 1]
# #인덱스 값을 10의 자리수로 포함해서 그게 범위 (10~26)에 들어간다면
# dp[i] += dp[i - 2]