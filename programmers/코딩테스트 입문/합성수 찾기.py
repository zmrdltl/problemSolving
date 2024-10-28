def divisor_cnt(n):
    divisor = 0
    for i in range(1, n+1):
        if n % i == 0:
            divisor += 1
    return divisor

def solution(n):
    answer = 0
    for i in range(1, n+1):
        if divisor_cnt(i) > 2:
            answer += 1
    return answer