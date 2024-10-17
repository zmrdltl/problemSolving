def solution(numbers, n):
    answer = 0
    for num in numbers:
        answer += num
        if answer > n:
            break
    return answer