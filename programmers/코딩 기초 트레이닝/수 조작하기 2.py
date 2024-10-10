def solution(numLog):
    answer = ''
    for i in range(1, len(numLog)):
        prev = numLog[i-1]
        next = numLog[i]
        if next - prev == 1:
            answer += 'w'
        elif next - prev == -1:
            answer += 's'
        elif next - prev == 10:
            answer += 'd'
        else:
            answer += 'a'
    return answer