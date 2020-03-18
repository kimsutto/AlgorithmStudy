def solution(arr):
    arr.pop(arr.index(min(arr)))
    if not arr:      #empty list= false
        arr=[-1]
    return arr
