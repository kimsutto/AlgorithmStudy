def solution(x):
    sum=0
    
    for i in str(x):
        sum+=int(i)
    
    return not x%sum
