def sum_of_list(num_list):
    sum = 0
    for num in num_list:
        sum += num
    return sum

def multiply_of_list(num_list):
    mul = 1
    for num in num_list:
        mul *= num
    return mul

def solution(num_list):
    if len(num_list) >= 11:
        return sum_of_list(num_list)
    return multiply_of_list(num_list)