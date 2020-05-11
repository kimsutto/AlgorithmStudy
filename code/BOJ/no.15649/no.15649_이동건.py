N, M = map(int, input().split())

num_list = [i + 1 for i in range(N)]
check_list = [False] * N

arr = []


def dfs(cnt):
    # 주어진 개수만큼 채워지면 출력한다
    if (cnt == M):
        print(*arr)
        return

    for i in range(0, N):
        if (check_list[i]):
            continue

        check_list[i] = True
        arr.append(num_list[i])
        dfs(cnt + 1)
        arr.pop()
        check_list[i] = False

dfs(0)