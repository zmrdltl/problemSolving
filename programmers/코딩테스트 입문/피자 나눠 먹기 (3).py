def solution(slice, n):
    answer = 0
    if n % slice > 0:
        answer += 1
    answer += n // slice
    return answer