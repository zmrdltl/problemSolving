def solution(arr, queries):
    answer = []
    for query in queries:
        s = query[0]
        e = query[1]
        k = query[2]
        minNum = 0x3f3f3f3f
        for i in range(s, e + 1):
            if arr[i] > k:
                minNum = min(arr[i], minNum)
        if minNum == 0x3f3f3f3f:
            answer.append(-1)
        else:
            answer.append(minNum)
    return answer