n = []
k = int(input())
for i in range(k):
    h = list(map(int, input().split()))
    n.append(h)

t = 2
for i in range(1, k):
    for j in range(t):
        if(j == 0):
            n[i][j] = n[i][j] + n[i-1][0]
        elif(j == i):
            n[i][j] = n[i][j] + n[i-1][j-1]
        else:
            n[i][j] = max(n[i-1][j-1], n[i-1][j]) + n[i][j]
    t = t + 1

print(max(n[k-1]))
