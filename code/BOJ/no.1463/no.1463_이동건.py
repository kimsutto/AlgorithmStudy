def min(x, y):
    return x if x <= y else y

n = int(input())

lst = [0 for _ in range(0, n + 1)]
index = 0

while(True):
    if index > n:
        break

    if(index <= 1):
        lst[index] = 0
        index = index + 1

    else:
        tmp_min = n + 1
        if(index % 3 == 0):
            tmp_index = int(index / 3)
            tmp_min = min(tmp_min, lst[tmp_index])

        if(index % 2 == 0):
            tmp_index = int(index / 2)
            tmp_min = min(tmp_min, lst[tmp_index])

        tmp_min = min(tmp_min, lst[index - 1])

        lst[index] = int(tmp_min + 1)

    index = index + 1

print(lst[n])