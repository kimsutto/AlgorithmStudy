def solution(citations):
    n=[]
    citations.sort()
    
    for i in range(citations[0],citations[-1]+1):
        count=0
        for j in citations:
            if j>=i:
                count+=1
        if count>=i:
            n.append(i)
    
    if not n:return len(citations)
        
    return n[-1]
