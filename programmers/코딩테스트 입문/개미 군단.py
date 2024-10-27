def solution(hp):
    answer = 0
    warload_ants = hp // 5
    soldier_ants = hp % 5 // 3
    general_ants = hp % 5 % 3
    return warload_ants + soldier_ants + general_ants