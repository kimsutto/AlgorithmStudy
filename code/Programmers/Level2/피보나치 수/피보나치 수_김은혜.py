def solution(n):
    answer = 0
    answer1 = 0
    answer2 = 1
    
    for i in range(2,n+1):
        answer=(answer1+answer2)
        answer1=answer2
        answer2=answer
    
    return answer%1234567
