def solution(s):
    answer = []
    for i in range(len(s) - 1):
        for j in range(i + 2, len(s) + 2):
            origin = s[i: j]
            if origin == origin[::-1]:
                answer.append(len(origin))
                print(origin)
    if len(answer) == 0 or len(s) == 1:
        return 1
    return max(answer)