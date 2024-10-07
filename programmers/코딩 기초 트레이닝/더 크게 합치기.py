def solution(a, b):
    a_concat_b = int(str(a)+str(b))
    b_concat_a = int(str(b)+str(a))
    if a_concat_b >= b_concat_a:
        return a_concat_b
    return b_concat_a