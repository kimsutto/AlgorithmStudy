a = int(input())
b = a
for i in range(1, b+1):
    print('*' * i)
for j in range(1, a):
    print('*' * (b - j))