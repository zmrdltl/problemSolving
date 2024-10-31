def solution(array):
    answer = 0
    for num in array:
        while num > 0:
            if num % 10 == 7:
                answer += 1
            num = num // 10
    return answer