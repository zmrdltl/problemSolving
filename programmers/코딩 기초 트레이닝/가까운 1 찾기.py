def solution(arr, idx):
    answer = -1
    for i in range(0, len(arr)):
        if i >= idx and arr[i] == 1:
            answer = i
            break
    return answer