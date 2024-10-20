def solution(binomial):
    answer = 0
    binomial = binomial.split(' ')
    a = int(binomial[0])
    op = binomial[1]
    c = int(binomial[2])
    if op == '+':
        return a + c
    elif op == '-':
        return a - c
    return a * c