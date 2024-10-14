def isNumberOnlyContainZeroAndFive(num_str):
    for num_char in num_str:
        if num_char != '0' and num_char != '5':
            return False
    return True

def solution(l, r):
    answer = []
    for num in range(l, r + 1):
        if isNumberOnlyContainZeroAndFive(str(num)):
            answer.append(num)
    if not answer:
        answer.append(-1)
    return answer