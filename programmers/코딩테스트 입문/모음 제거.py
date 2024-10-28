def solution(my_string):
    for char in "aeiou":
        my_string = my_string.replace(char,"")
    return my_string