# 0
# 0 0 1
# 0 0 1 0 0 1 1
# 0 0 1 0 0 1 1 0 0 0 1 1 0 1 1
# 중간 기준 대칭
# 전에 거가 반대로 감

n = 4

def solution(n):
    answer = []

    for i in range(n+1):
        if(i == 0):
            pass
        elif(i == 1):
            answer.append(0)
        else:
            tmp = []
            for j in answer:
                if(j == 0):
                    tmp.append(1)
                else:
                    tmp.append(0)
            answer.append(0)
            if(len(tmp) > 1):
                answer = answer + list(reversed(tmp))
            else:
                answer = answer + tmp

    return answer

print(solution(n))