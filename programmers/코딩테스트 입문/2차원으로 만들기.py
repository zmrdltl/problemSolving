def solution(num_list, n):
    answer = []
    for i in range(0, len(num_list), n):
        list = []
        for j in range(i, i+n):
            list.append(num_list[j])
        answer.append(list)
    return answer