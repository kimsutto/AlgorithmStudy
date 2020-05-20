def solution(scoville, K):
    count=0
    
    while (min(scoville)<K):
        scoville.sort()
        scoville.append(scoville[0]+scoville[1]*2)
        scoville.remove(scoville[0])
        scoville.remove(scoville[0])
        count+=1
        if len(scoville)==1 and scoville[0]<K:
            return -1
        
    return count
