def solution(arr, queries):
    for query in queries:
        s = query[0]
        e = query[1]
        k = query[2]
        for i in range(s, e+1):
            if i % k == 0:
                arr[i]+=1
    return arr