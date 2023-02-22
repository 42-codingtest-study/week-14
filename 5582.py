str1 = input()
str2 = input()
lcs = [[0] * 4001 for _ in range(4001)]
ans = 0
for i in range(1, len(str1) + 1) :
    for j in range(1, len(str2) + 1) :
        if str1[i - 1] == str2[j - 1] :
            lcs[i][j] = lcs[i - 1][j - 1] + 1
        if lcs[i][j] > ans :
            ans = lcs[i][j]
print(ans)
