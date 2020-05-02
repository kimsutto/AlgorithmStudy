from collections import deque

board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
moves = [1, 5, 3, 5, 1, 2, 1, 4]


def solution(board, moves):
    count = 0

    stack = deque()

    for i in range(len(moves)):
        for j in range(len(board)):

            if(board[j][moves[i]-1] != 0):

                if(stack):
                    if (stack[-1] == board[j][moves[i] - 1]):
                        count = count + 2
                        stack.pop()
                    else:
                        stack.append(board[j][moves[i] - 1])

                else:
                    stack.append(board[j][moves[i] - 1])


                board[j][moves[i] - 1] = 0
                break

    return count


print(solution(board, moves))
