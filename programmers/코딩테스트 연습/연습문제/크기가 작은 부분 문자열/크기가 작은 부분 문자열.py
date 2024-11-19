def solution(t, p):
    answer = 0
    p_len = len(p);
    for i in range(0, len(t)-p_len+1):
        sub_str = t[i:i+p_len]
        if sub_str <= p:
            answer += 1;
    return answer