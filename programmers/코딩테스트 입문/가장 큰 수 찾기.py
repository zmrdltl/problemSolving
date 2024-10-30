def solution(array):
    idx = 0
    maxNum = 0
    for index in range(0, len(array)):
        num = array[index]
        if num > maxNum:
            maxNum = num
            idx = index
    return [maxNum, idx]