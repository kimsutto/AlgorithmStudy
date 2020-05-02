n, m = map(int, input().split())

a = list(map(int, input().split()))

k = len(a)
temp = 0

for i in range(k - 2):
    for j in range(i+1, k - 1):
        for l in range(j+1, k):
            if(a[i] + a[j] + a[l] > m):
                pass
            else:
                temp = max(temp, a[i] + a[j] + a[l])

print(temp)
