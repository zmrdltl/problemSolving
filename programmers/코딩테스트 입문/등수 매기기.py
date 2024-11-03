def solution(score):
    answer = [0] * len(score)
    idx_avg_dict = {}
    
    for i, s in enumerate(score):
        s = score[i]
        avg = (s[0] + s[1]) / 2
        idx_avg_dict[i] = avg
    idx_avg_dict = dict(sorted(idx_avg_dict.items(), key = lambda item: item[1], reverse=True))
    
    rank = 1
    prev_avg = -1
    same_cnt = 0
    for idx, avg in idx_avg_dict.items():
        if prev_avg == avg:
            same_cnt += 1
        else:
            prev_avg = avg
            rank += same_cnt
            same_cnt = 1
        answer[idx] = rank
    return answer