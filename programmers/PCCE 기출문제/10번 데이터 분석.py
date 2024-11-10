def solution(data, ext, val_ext, sort_by):
    key_map = {'code': 0, 'date': 1, 'maximum': 2, 'remain': 3}
    answer = [d for d in data if d[key_map[ext]] <= val_ext]
    answer = sorted(answer, key = lambda x: x[key_map[sort_by]])
    return answer