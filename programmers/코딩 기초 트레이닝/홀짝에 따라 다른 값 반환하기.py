def solution(n):
    answer = 0
    while n > 0:
        if n % 2 == 0:
            answer += n*n
        else:
            answer += n
        n -= 2
    return answer