n, m = map(int, input().split())

numlist = [i+1 for i in range(n)]
checklist = [False] * n

arr = []

def dfs(cnt):
    if(cnt == m):
        print(*arr)
        return
    for i in range(n):
        if(checklist[i]):
            continue

        checklist[i] = True
        arr.append(numlist[i])
        dfs(cnt+1)
        arr.pop()


        for j in range(i + 1, n):
            checklist[j] = False


dfs(0)
