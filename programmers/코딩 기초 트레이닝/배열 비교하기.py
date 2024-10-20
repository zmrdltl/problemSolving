def sum_of(arr):
    sum = 0
    for a in arr:
        sum += a
    return sum

def solution(arr1, arr2):
    answer = 0
    if len(arr1) > len(arr2):
        answer = 1
    elif len(arr1) < len(arr2):
        answer = -1
    else:
        arr1_sum = sum_of(arr1)
        arr2_sum = sum_of(arr2)
        if arr1_sum > arr2_sum:
            answer = 1
        elif arr1_sum < arr2_sum:
            answer = -1
    return answer