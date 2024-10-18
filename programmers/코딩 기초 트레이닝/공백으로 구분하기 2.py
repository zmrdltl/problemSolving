def solution(my_string):
    answer = []
    my_string = my_string.split(' ')
    for str in my_string:
        if str == '':
            continue
        answer.append(str)
    return answer