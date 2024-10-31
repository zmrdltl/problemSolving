def solution(my_string):
    answer = 0
    tmp = 0
    for char in my_string:
        if char.isdigit():
            tmp = 10 * tmp + int(char)
        else:
            answer += tmp
            tmp = 0
    return answer + tmp