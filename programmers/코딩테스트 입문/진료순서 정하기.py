def solution(emergency):
    answer = []
    emergency_copy = emergency.copy()
    emergency_copy.sort(reverse=True)
    emergency_rank = {}
    for i in range(0, len(emergency_copy)):
        e = emergency_copy[i]
        emergency_rank[e] = i + 1
    for e in emergency:
        answer.append(emergency_rank[e])
    return answer