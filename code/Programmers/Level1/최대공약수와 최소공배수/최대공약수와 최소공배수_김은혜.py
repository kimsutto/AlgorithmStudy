def solution(n, m):
    answer = [0,0]
    
    for i in range(1,min(n,m)+1):
        if max(n,m)%i==0 and min(n,m)%i==0:
            answer[0]=i
    
    for i in range(max(n,m),n*m+1):
        if i%n==0 and i%m==0:
            answer[1]=i
            break
    
    return answer
