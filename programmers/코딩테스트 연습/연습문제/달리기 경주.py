def solution(players, callings):
    answer = players
    name_idx_dict = {}
    for i in range(len(players)):
        p = players[i]
        name_idx_dict[p] = i
    for c in callings:
        cur_idx = name_idx_dict.get(c)
        name_idx_dict[answer[cur_idx]] = cur_idx - 1
        name_idx_dict[answer[cur_idx-1]] = cur_idx
        answer[cur_idx-1], answer[cur_idx] = answer[cur_idx], answer[cur_idx-1]
    return answer