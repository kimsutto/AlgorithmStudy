def solution(s, n):
    answer =[]
    
    for i in s:
        if ord(i)==32:
            answer.append(' ')
            
        elif ord(i)<=90 and 90<(ord(i)+n):
            answer.append(chr(ord(i)+n-26))
            
        elif 97<=ord(i) and 122<(ord(i)+n):
            answer.append(chr(ord(i)+n-26))
        
        else:
            answer.append(chr(ord(i)+n))
            
    return (''.join(answer))
