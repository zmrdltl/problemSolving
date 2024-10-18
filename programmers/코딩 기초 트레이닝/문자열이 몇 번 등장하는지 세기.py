def solution(myString, pat):
    answer = 0
    for i in range(0, len(myString)):
        sliced = myString[i:]
        if sliced.startswith(pat):
            answer += 1
    return answer