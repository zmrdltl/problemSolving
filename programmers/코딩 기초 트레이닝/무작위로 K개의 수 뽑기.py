def solution(arr, k):
    answer = []
    dict = {}
    for a in arr:
        if len(answer) >= k:
            break
        frequency = dict.get(a,0)
        if frequency == 0:
            answer.append(a)
        dict[a] = frequency + 1
    if len(answer) < k:
        answer.extend([-1] * (k - len(answer)))
    return answer