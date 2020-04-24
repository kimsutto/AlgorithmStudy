def solution(s):
    count=0
    list_s=list(s)
    
    for i in range(len(list_s)):
        if list_s[i]==' ':
            count=-1
        if count%2==0:
            list_s[i]=list_s[i].upper()
        else:
            list_s[i]=list_s[i].lower()
        count+=1
        
    return ''.join(list_s)
