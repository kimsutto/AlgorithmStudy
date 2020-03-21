def solution(arr):
    answer = [arr[0]]
    i=0
    while i<len(arr):
        if arr[i-1] != arr[i]:
            answer.append(arr[i])
        i+=1
    return answer
