def solution(my_string):
    my_list = list(my_string)
    for i in range(0, len(my_list)):
        my_list[i] = my_list[i].lower()
    my_list.sort()
    return ''.join(my_list)