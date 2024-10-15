def solution(my_string, m, c):
    answer = ''
    sequence = 0
    while sequence * m + c - 1 < len(my_string):
        piv = sequence * m + c - 1
        answer += my_string[piv]
        sequence += 1
    return answer