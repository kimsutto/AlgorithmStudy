def solution(n, lost, reserve):
    student=[1]*n
    
    for i in lost:
        student[i-1]-=1
    for i in reserve:
        student[i-1]+=1
    
    if student[0]==0 and student[1]==2:
        student[0]+=1
        student[1]-=1
    
    for i in range(1,n-1):
        if student[i]==0:
            if student[i-1]==2:
                student[i]+=1
                student[i-1]-=1
            elif student[i+1]==2:
                student[i]+=1
                student[i+1]-=1
                
    return n-student.count(0)
