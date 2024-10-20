def solution(arr):
    answer = arr
    append_len = 1
    while append_len < len(arr):
        append_len *= 2
    append_len -= len(arr)
    answer.extend([0]*append_len)
    return answer