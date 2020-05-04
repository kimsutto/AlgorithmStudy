stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]
k = 3

# 이분 탐색으로 풀기

def calc(stones, k, mid):
    now = 0

    for stone in stones:
        if(stone < mid):
            now += 1
        else:
            now = 0
        if(now >= k):
            return False

    return True


def solution(stones, k):

    # 이분 탐색을 위한 min과 max 정하기

    left = 1
    right = max(stones) + 1

    while(left < right - 1):
        mid = (left + right) // 2

        if(calc(stones, k, mid)):
            left = mid
        else:
            right = mid


    return left

print(solution(stones, k))