def solution (arrangement):
    token_stack = []
    answer = 0

    for token in arrangement:
        if token == "(":
            token_stack.append(token)
            last = token
        else:
            if last == "(":
                token_stack.pop()
                answer += len(token_stack)
                last = token
            else:
                token_stack.pop()
                answer += 1

    return answer
