import sys
n = int(sys.stdin.readline())
f = 1
s = 2
tmp = 0
for i in range(n - 1):
    tmp = f
    f = s
    s = (tmp + s) % 15746
print(f)