def status(ineq, eq):
    if ineq == '<' and eq == '=': 
        return 'less than equal'
    if ineq == '<' and eq == '!': 
        return 'less than'
    if ineq == '>' and eq == '=': 
        return 'greater than equal'
    return 'greater than'

def solution(ineq, eq, n, m):
    answer = 0
    status_string = status(ineq, eq)

    if status_string == 'less than equal':
        if n <= m:
            answer = 1
    elif status_string == 'less than':
        if n < m:
            answer = 1
    elif status_string == 'greater than equal':
        if n >= m:
            answer = 1
    elif status_string == 'greater than':
        if n > m:
            answer = 1

    return answer