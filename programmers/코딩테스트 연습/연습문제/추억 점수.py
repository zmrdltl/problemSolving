def solution(name, yearning, photo):
    answer = []
    name_yearning_dict = {}
    for i in range(len(name)):
        name_yearning_dict[name[i]] = name_yearning_dict.get(name[i],yearning[i])
    for p in photo:
        y = 0
        for name in p:
            y += name_yearning_dict.get(name,0)
        answer.append(y)
    return answer