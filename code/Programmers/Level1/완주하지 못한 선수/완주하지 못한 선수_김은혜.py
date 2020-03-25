import collections
def solution(participant, completion):
    answer=collections.Counter(participant)-collection.Counter(completion)
    return list(answer.keys())[0]
