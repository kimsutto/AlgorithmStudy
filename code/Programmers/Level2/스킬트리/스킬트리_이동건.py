skill = "CBD"
skill_trees = ["BACDE", "CBADF", "AECB", "BDA"]

def solution(skill, skill_trees):
    answer = 0


    for i in skill_trees:
        tmp = []
        for j in skill:
            tmp.append(i.find(j))

        for j in range(len(tmp)):
            if(tmp[-1] == -1):
                tmp.pop()
            else:
                break

        if(-1 not in tmp):
            stmp = sorted(tmp)
            if(tmp == stmp):
                answer += 1

    return answer

print(solution(skill, skill_trees))