import copy
def is_same_arr(cur_arr, prev_arr):
    for i in range(0, len(cur_arr)):
        if cur_arr[i] != prev_arr[i]:
            return False
    return True

def calculate_arr(arr):
    for i in range(0, len(arr)):
        a = arr[i]
        if a >= 50 and a % 2 == 0:
            a //= 2
        elif a < 50 and a % 2 == 1:
            a = a * 2 + 1
        arr[i] = a
        
def solution(arr):
    cur_arr = arr
    x = 0
    while True:
        prev_arr = cur_arr.copy()
        calculate_arr(cur_arr)
        if is_same_arr(cur_arr, prev_arr):
            break
        x += 1
        
    return x