def solution(spell, dic):
    spell_str = ''.join(sorted(spell))
    for d in dic:
        d = ''.join(sorted(d))
        if spell_str == d:
            return 1
    return 2