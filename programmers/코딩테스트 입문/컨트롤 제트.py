def solution(s):
    answer = 0
    s = s.split(' ')
    for i in range(0,len(s)):
        char = s[i]
        if char == 'Z':
            answer -= int(s[i-1])
        else:
            answer += int(char)
        
    return answer