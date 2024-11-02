def solution(babbling):
    answer = 0
    for b in babbling:
        made_str = ""
        if b.find('aya') != -1:
            made_str += 'aya'
        if b.find('ye') != -1:
            made_str += 'ye'
        if b.find('woo') != -1:
            made_str += 'woo'
        if b.find('ma') != -1:
            made_str += 'ma'
        b = sorted(b)
        made_str = sorted(made_str)
        if b == made_str:
            answer += 1
    return answer