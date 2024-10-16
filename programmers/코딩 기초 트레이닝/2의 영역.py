def solution(arr):
    answer = []
    index_of_twos = [i for i in range(0,len(arr)) if arr[i] == 2]
    len_of_twos = len(index_of_twos)
    if len_of_twos == 0:
        return [-1]
    left = index_of_twos[0]
    right = index_of_twos[len_of_twos - 1]
    answer = arr[left:right+1]
    
    return answer