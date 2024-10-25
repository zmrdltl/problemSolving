def solution(my_string, letter):
    answer = ''.join([c for c in my_string if letter.find(c) == -1])
    return answer