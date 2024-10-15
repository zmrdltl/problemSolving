def solution(q, r, code):
    answer = ''
    for i in range(0, len(code)):
        if i % q == r:
            answer += code[i]
    return answer