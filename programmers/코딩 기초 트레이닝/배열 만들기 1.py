def solution(n, k):
    answer = []
    piv = k
    while piv <= n:
        answer.append(piv)
        piv += k
    return answer