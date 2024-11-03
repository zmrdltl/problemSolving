def solution(n):
    answer = 0
    for i in range(1,n+1):
        answer += 1
        while answer % 3 == 0 or str(answer).find('3') >= 0:
            answer += 1
    return answer