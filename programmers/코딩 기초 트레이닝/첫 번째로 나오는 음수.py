def solution(num_list):
    answer = -1
    for i in range(0, len(num_list)):
        if num_list[i] < 0:
            answer = i
            break
    return answer