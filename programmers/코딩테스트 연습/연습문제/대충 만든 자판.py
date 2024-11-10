def solution(keymap, targets):
    answer = []
    char_press_map = {}
    for i in range(26):
        char = chr(i+65)
        min_press = 0x3f3f3f3f
        for keys in keymap:
            if char in keys:
                min_press = min(min_press, keys.index(char) + 1)
        char_press_map[char] = min_press
    for target in targets:
        pressed = 0
        for i in range(len(target)):
            min_press = char_press_map[target[i]]
            if min_press == 0x3f3f3f3f:
                pressed = -1
                break
            pressed += min_press
        answer.append(pressed)
    return answer