def solution(s1, s2):
    answer = 0
    for char in s1:
        if s2.count(char) > 0:
            answer += 1
    return answer