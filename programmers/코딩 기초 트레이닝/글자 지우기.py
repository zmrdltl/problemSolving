def solution(my_string, indices):
    str_list = list(my_string)
    indices.sort(reverse=True)
    for indice in indices:
        del str_list[indice]
    return ''.join(str_list)