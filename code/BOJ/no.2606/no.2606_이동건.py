from collections import deque

n = int(input())
m = int(input())



graph = {}

for i in range(m):
    a, b = map(int, input().split())
    if a not in graph:
        graph[a] = [b]
    elif b not in graph[a]:
        graph[a].append(b)

    if b not in graph:
        graph[b] = [a]
    elif a not in graph[b]:
        graph[b].append(a)


def bfs(graph):
    visited = []
    queue = deque([1])

    while(queue):
        n = queue.popleft()

        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue = queue + deque(temp)
    return len(visited)

def dfs(graph):
    visited = []
    stack = [1]

    while(stack):
        n = stack.pop()

        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack = stack + temp
    return len(visited)


print(dfs(graph) - 1)
#print(bfs(graph) - 1)