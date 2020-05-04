from collections import Counter
def solution(clothes):
    n = []
    answer=1
    
    for i in clothes:
        n.append(i[1])
        
    n=Counter(n)
    
    for i in n.values():
        answer*=(i+1)
        
    return answer-1
