def win_case(one_game):
    if one_game == '2':
        return '0'
    if one_game == '0':
        return '5'
    return '2'

def solution(rsp):
    answer = ''
    for char in rsp:
        answer += win_case(char)
    return answer