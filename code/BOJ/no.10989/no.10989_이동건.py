import sys
N = int(input())
cnt_list = [0] * 10001

for i in range(N):
    cnt_list[int(input())] += 1

for i in range(10001):
    sys.stdout.write('%s\n' % i * cnt_list[i])