def solution(intStrs, k, s, l):
    answer = []
    for intStr in intStrs:
        slicedStr = int(intStr[s:s+l])
        if slicedStr > k:
            answer.append(int(slicedStr))
    return answer