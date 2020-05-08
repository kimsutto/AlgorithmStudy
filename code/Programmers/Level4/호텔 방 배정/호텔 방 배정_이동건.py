k = 40
room_number = [1, 5, 4, 2, 3, 5, 4,3, 2, 1, 5, 3, 24, 15, 16, 4, 3, 2,6, 7, 8, 11, 21, 11, 14, 14, 15 ]

def sortque(dict, i):
    if (i not in dict.keys()):
        dict[i] = 1
    else:
        v = dict[i]
        dict[i] += 1
        sortque(dict, i+v)

def solution(k, room_number):
    dict = {}
    for i in room_number:
        sortque(dict, i)

    answer = []
    keys = dict.keys()
    for j in keys:
        answer.append(j)
    return answer


print(solution(k, room_number))