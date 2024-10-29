def solution(order):
    answer = 0
    while order > 0:
        num = order % 10
        if num == 3 or num == 6 or num == 9:
            answer += 1
        order = order // 10
    return answer