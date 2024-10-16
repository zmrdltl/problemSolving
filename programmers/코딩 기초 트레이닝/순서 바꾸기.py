def solution(num_list, n):
    arr1 = num_list[0:n]
    arr2 = num_list[n:]
    arr2.extend(arr1)
    return arr2