def solution(num_list):
    answer = 0
    odd_sum, even_sum = 0, 0
    for i in range(0, len(num_list)):
        num = num_list[i]
        if i % 2 == 1:
            even_sum += num
        else:
            odd_sum += num
    return max(odd_sum, even_sum)