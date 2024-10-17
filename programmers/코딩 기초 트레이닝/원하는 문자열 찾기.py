def solution(myString, pat):
    answer = 0
    str_len = len(myString)
    pat_len = len(pat)
    if str_len >= pat_len and myString.lower().find(pat.lower()) != -1:
        answer = 1
    return answer
