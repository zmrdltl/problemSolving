def solution(order):
    answer = 0
    for ord in order:
        if ord.find("americano") != -1 or ord.find("anything") != -1:
            answer += 4500
        else:
            answer += 5000
    return answer