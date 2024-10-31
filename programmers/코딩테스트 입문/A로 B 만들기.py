def solution(before, after):
    before_dict = {}
    for b in before:
        before_dict[b] = before_dict.get(b,0) + 1
    for a in after:
        before_dict[a] = before_dict.get(a,0) - 1
        if before_dict.get(a) < 0:
            return 0
    return 1