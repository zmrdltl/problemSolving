def solution(arr, flag):
    x = []
    for i in range(0, len(flag)):
        if flag[i]:
            x.extend([arr[i]]*arr[i]*2)
        else:
            x = x[:-arr[i]]
    return x