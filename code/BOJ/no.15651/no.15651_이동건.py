n, m = map(int, input().split())

numlist = [i+1 for i in range(n)]

arr = []

def dfs(cnt):
    if(cnt == m):
        print(*arr)
        return
    for i in range(n):

        arr.append(numlist[i])
        dfs(cnt+1)
        arr.pop()

dfs(0)
