import sys
from collections import Counter

t = int(sys.stdin.readline())
num_list = []
for _ in range(t):
    num_list.append(int(sys.stdin.readline()))


def mode(x):
    mode_dict = Counter(x)
    modes = mode_dict.most_common()
    if len(x) > 1:
        if modes[0][1] == modes[1][1]:
            mod = modes[1][0]
        else:
            mod = modes[0][0]
    else:
        mod = modes[0][0]

    return mod


print(round(sum(num_list) / len(num_list)))
num_list.sort()
print(num_list[len(num_list) // 2])
print(mode(num_list))
print(num_list[-1] - num_list[0])