def solution(my_strings, parts):
    answer = ''
    for i in range(0, len(parts)):
        part = parts[i]
        answer += my_strings[i][part[0]:part[1]+1]
    return answer