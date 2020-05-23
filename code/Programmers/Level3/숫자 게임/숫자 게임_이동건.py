A = [5,1,3,7]
B = [2,2,6,8]

def solution(A, B):
    card = 0
    tmpA = list(sorted(A))
    tmpB = list(sorted(B))
    for i in tmpA:
        for j in tmpB:
            if(j > i):
                card += 1
                tmpB.remove(j)
                break

    return card

print(solution(A, B))