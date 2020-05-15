n, m = map(int, input().split())

numlist = [i+1 for i in range(n)]
checklist = [False] * n

arr = []

def dfs(count):
    for i in range(n):
        if(count == m):
            print(*arr)
            return

        if(checklist[i] == True):
            continue

        arr.append(numlist[i])
        dfs(count+1)
        arr.pop()
        checklist[i] = True

        for j in range(i+1, n):
            checklist[j] = False


dfs(0)