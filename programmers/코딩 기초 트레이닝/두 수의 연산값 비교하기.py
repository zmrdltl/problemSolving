def solution(a, b):
    concatedNum = int(str(a) + str(b))
    calculatedNum = 2*a*b
    if concatedNum >= calculatedNum:
        return concatedNum
    return calculatedNum