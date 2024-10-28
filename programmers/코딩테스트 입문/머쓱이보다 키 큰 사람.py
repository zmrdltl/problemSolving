def solution(array, height):
    answer = 0
    for num in array:
        if num > height:
            answer += 1
    return answer