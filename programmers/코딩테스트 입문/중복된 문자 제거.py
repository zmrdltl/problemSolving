def solution(my_string):
    answer = ''
    dict = {}
    for char in my_string:
        if dict.get(char) is None:
            dict[char] = 1
            answer += char
    return answer