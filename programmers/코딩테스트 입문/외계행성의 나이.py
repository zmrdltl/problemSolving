def solution(age):
    answer = ''
    age_str = str(age)
    for char in age_str:
        answer += chr(int(char)+97)
    return answer