import sys

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())
d = int(sys.stdin.readline())
e = int(sys.stdin.readline())

buger = min(a, b, c)
drink = min(d, e)

set = buger + drink - 50

print(set)