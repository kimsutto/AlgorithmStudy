from collections import deque

n, m, v = map(int, input().split())

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


def bfs(graph, v):
    visited = []
    queue = deque([v])

    while(queue):
        n = queue.popleft()

        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue = queue + deque(temp)
    return " ".join(str(i) for i in visited)

def dfs(graph, v):
    visited = []
    stack = [v]

    while(stack):
        n = stack.pop()

        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack = stack + temp
    return " ".join(str(i) for i in visited)


print(dfs(graph, v))
print(bfs(graph, v))