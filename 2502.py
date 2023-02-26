D, K = map(int, input().split())
day = [[1, 0]]
day.append([0, 1])
for i in range(1, D) :
    day.append([day[i - 1][0] + day[i][0], day[i - 1][1] + day[i][1]])
for i in range(1, K) :
    for j in range(1, K) :
        if i * day[D - 1][0] + j * day[D - 1][1] == K :
            print(i, j, sep = "\n")
            exit(0)
