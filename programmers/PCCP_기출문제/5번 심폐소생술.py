def solution(cpr):
    answer = []
    basic_order = ["check", "call", "pressure", "respiration", "repeat"]
    for action in cpr:
        for i in range(0,len(basic_order)):
            if action == basic_order[i]:
                answer.append(i+1)
    return answer