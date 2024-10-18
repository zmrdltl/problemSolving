def solution(myString, pat):
    answer = ''
    for i in range(1, len(myString)+1):
        sliced = myString[:i]
        if sliced.endswith(pat):
            answer = sliced
    return answer