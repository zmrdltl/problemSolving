def solution(array, n):
    answer = 0x3f3f3f3f
    diff = 0x3f3f3f3f
    array.sort()
    for num in array:
        if diff > abs(num - n):
            answer = num
            diff = abs(num - n)
    return answer