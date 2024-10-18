def solution(n):
    answer = []
    for col in range(0, n):
        arr = [0] * n
        arr[col] = 1
        answer.append(arr)
    return answer