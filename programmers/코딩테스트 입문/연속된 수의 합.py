def solution(num, total):
    answer = []
    for i in range(-1000, 1000-num):
        sum = 0
        for j in range(i, i + num):
            sum += j
        if sum == total:
            for j in range(i, i + num):
                answer.append(j)
    return answer