def solution(my_string, is_suffix):
    answer = 0
    if my_string.endswith(is_suffix):
        answer = 1
    return answer