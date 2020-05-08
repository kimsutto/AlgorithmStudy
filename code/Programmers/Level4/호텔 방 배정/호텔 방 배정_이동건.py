k = 40
room_number = [1, 5, 4, 2, 3, 5, 4,3, 2, 1, 5, 3, 24, 15, 16, 4, 3, 2,6, 7, 8, 11, 21, 11, 14, 14, 15 ]


def solution(k, room_number):
    dict = {}
    for i in room_number:
        if(i not in dict.keys()):
            dict[i] = i
        else:
            while(i in dict.keys()):
                i += 1

            dict[i] = i

    answer = []
    keys = dict.keys()
    for j in keys:
        answer.append(j)
    return answer


print(solution(k, room_number))