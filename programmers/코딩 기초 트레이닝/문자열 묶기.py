def solution(strArr):
    answer = 0
    dict = {}
    for str in strArr:
        dict[len(str)] = dict.get(len(str),0) + 1
    for _, val in dict.items():
        answer = max(answer, val)
    return answer