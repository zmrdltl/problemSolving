def solution(arr):
    answer = 1
    n = len(arr)
    for row in range(0, n):
        for col in range(0, n):
            if arr[row][col] != arr[col][row]:
                answer = 0
            
    return answer