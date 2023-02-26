import sys
input = sys.stdin.readline

n = list(map(int, input().strip()))
length = len(n)
count = 0
dp = [0] * (length + 1)

lst = []
for i in range(26):
    lst.append(i+1)

    
if n [0]== 0:
    print("0")
    exit()
n = [0] + n #025114
# print(n)
dp[0], dp[1] = 1, 1 #25114 -> 110000

for i in range(2,length+1):
    if 10 <= n[i-1]*10 + n[i] <= 26: 
        # print(dp)
        # print(i , ":" ,dp[i])
        dp[i] += dp[i-2]  
        print(i , ":" ,dp[i])
        
    if 1 <= n[i] <= 9:
        dp[i] += dp[i-1]
        print(i , ":" ,dp[i])
        
print(dp[length]%1000000)


    