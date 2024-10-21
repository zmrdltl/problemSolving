def solution(myString):
    answer = ''
    str_list = list(myString)
    for i in range(0, len(str_list)):
        if str_list[i] < "l":
            str_list[i] = "l"
    return ''.join(str_list)