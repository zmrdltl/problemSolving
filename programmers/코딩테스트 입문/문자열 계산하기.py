def solution(my_string):
    my_string = my_string.split(' ')
    
    lh = int(my_string[0])
    op = my_string[1]
    
    for i in range(2, len(my_string)):
        char = my_string[i]
        if char == '+' or char == '-':
            op = char
        else:
            if op == '+':
                lh += int(char)
            else:
                lh -= int(char)
    return lh