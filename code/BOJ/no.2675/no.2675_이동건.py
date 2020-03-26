import sys
t = int(input())

for i in range(t):
    r, s = sys.stdin.readline().split()
    rNum = int(r)
    k = ''
    for j in s:
        k += j * rNum
    print(k)