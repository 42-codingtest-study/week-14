#2의 멱수의 합

def solution(n):
    nums = [2 ** x for x in range(21)]
    dp = [0] * (n + 1)
    dp[0] = 1
    for num in nums:
        if num <= n:
            for j in range(num, n + 1):
                dp[j] += dp[j - num]
    print(dp[-1] % 1000000000)


if __name__ == "__main__":
    N = int(input())
    solution(N)