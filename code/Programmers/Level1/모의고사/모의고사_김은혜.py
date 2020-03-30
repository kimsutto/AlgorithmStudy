def solution(answers):
    answer = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    score=[]
    first=[]
    
    for i in answer:
        n=0
        count=0
        for j in answers:
            if j==i[n%len(i)]:
                count+=1
            n+=1
        score.append(count)
    
    n=1
    for i in score:
        if i==max(score):
            first.append(n)
        n+=1
    
    return first
