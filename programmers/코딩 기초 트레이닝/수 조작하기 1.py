def solution(n, control):
    answer = n
    for op in control:
        if op == 'w':
            answer += 1
        elif op == 's':
            answer -= 1
        elif op == 'd':
            answer += 10
        else:
            answer -= 10
    return answer