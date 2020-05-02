from collections import deque

board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
moves = [1, 5, 3, 5, 1, 2, 1, 4]


def solution(board, moves):
    count = 0

    l = len(board)
    array = [[0 for col in range(l)] for row in range(l)]
    for i in range(l):
        for j in range(l):
            array[i][j] = board[j][i]


    nb = []
    for i in range(l):
        nb.append(deque(reversed(array[i])))

    move = deque(moves)
    stack = []
    while (move):
        key = move.popleft() - 1
        st = 0
        while (st == 0):
            if (len(nb[key]) > 0):
                st = nb[key].pop()
            else:
                break
        if(st != 0):
            stack.append(st)
        if (len(stack) > 2):
            if (stack[-1] == stack[-2]):
                count = count + 2
                stack.pop()
                stack.pop()
        else:
            continue

    return count


print(solution(board, moves))
