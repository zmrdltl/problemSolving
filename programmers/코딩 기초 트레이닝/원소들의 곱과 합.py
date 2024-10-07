def solution(num_list):
    answer = 0
    sum = 0
    mul = 1
    for num in num_list:
        mul *= num
        sum += num
    if mul <= sum * sum:
        answer = 1
    return answer