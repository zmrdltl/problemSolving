def solution(arr, delete_list):
    for element in delete_list:
        if arr.count(element) > 0:
            arr.remove(element)
    return arr