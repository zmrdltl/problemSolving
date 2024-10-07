def solution(my_string, overwrite_string, s):
    my_string = my_string[:s] + overwrite_string[:len(my_string) - s] + my_string[len(overwrite_string)+s:]
    return my_string
