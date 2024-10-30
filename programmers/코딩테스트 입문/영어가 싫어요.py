def solution(numbers):
    answer = 0
    num_dict = {
        "zero": 0, 
        "one": 1, 
        "two": 2, 
        "three": 3, 
        "four": 4, 
        "five": 5, 
        "six": 6, 
        "seven": 7, 
        "eight": 8, 
        "nine": 9
    }
    str = ""
    for char in numbers:
        str += char
        if num_dict.get(str) is not None:
            answer += num_dict[str]
            answer *= 10
            str = ""
    return answer // 10