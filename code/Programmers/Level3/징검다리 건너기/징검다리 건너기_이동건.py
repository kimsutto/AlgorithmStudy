stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]
k = 3

def solution(stones, k):
    answer = 0

    while(1):

        # 1. 모든 돌 하나하나 탐색해 0인거 찾기

        for i in range(len(stones)):

            if (stones[i] == 0):
                # 2. 0인거 찾았으면 그거 포함 k+1개 탐색해서 0인지 판별
                for j in range(k):
                    if(i+j < len(stones)):
                        if (stones[i + j] != 0):
                            # 3. 0이 아니면 탈출
                            break
                        else:
                            # 4. j가 k+1이면 답 반환 (k개 넘게 0임) 아니면 계속 진행
                            if (j == k - 1):
                                return answer
                            else:
                                pass
            # 0이 아니면 1 빼주기
            else:
                stones[i] -= 1

        answer += 1


print(solution(stones, k))