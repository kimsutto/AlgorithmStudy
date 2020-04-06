t = int(input())
p = [1, 1, 1, 2, 2]

for k in range(5, 100):
    p.append(p[k-1] + p[k-5])

for i in range(t):
    n = int(input())
    print(p[n-1])