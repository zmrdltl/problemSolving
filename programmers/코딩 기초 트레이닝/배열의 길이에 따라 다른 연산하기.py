def solution(arr, n):
    arr_len = len(arr)
    for i in range(0, len(arr)):
        if arr_len % 2 == 1 and i % 2 == 0:
            arr[i] += n
        elif arr_len % 2 == 0 and i % 2 == 1:
            arr[i] += n
    return arr