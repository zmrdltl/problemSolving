def solution(arr):
    stk = []
    i = 0
    while i < len(arr):
        if not stk:
            stk.append(arr[i])
            i+=1
        if i < len(arr) and stk[-1] < arr[i]:
            stk.append(arr[i])
            i+=1
        if i < len(arr) and stk[-1] >= arr[i]:
            stk.pop()
    return stk