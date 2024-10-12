def solution(arr, queries):
    answer = arr
    for query in queries:
        answer[query[0]], answer[query[1]] = answer[query[1]], answer[query[0]]
    return answer