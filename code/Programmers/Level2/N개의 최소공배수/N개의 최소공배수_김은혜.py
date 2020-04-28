from fractions import gcd
def solution(arr):
    answer = arr[0]
    
    for i in arr[1:]:
        answer=answer*i/gcd(answer,i)
    
    return answer
