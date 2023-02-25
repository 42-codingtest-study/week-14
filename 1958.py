# LCS 3
# https://www.acmicpc.net/problem/1958

a = input()
b = input()
c = input()
LCS = [[[0] * 101 for _ in range(101)] for _ in range(101)]
for i in range(1, len(a) + 1) :
    for j in range(1, len(b) + 1) :
        for k in range(1, len(c) + 1) :
            if (a[i - 1] == b[j - 1] and a[i - 1] == c[k - 1]) :
                LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1
            else :
                LCS[i][j][k] = max(LCS[i - 1][j][k], LCS[i][j - 1][k], LCS[i][j][k - 1])
print(LCS[len(a)][len(b)][len(c)])
