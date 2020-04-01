n = int(input())
a = [0, 1]

for i in range(n):
    k = a[len(a) - 1] + a[len(a) - 2]
    a.append(k)

print(a[n])