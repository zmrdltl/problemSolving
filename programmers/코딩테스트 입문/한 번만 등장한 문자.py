def solution(s):
    char_count = []
    dict = {}
    for char in s:
        dict[char] = dict.get(char,0) + 1
    for key, count in dict.items():
        if count == 1:
            char_count.append(key)
    char_count.sort()
    return ''.join(char_count)