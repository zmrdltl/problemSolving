def get_total_sec(str):
    return int(str[0:2])*60 + int(str[3:])

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    total_sec = get_total_sec(video_len)
    if op_start <= pos and pos <= op_end:
        pos = op_end
    pos_sec = get_total_sec(pos)
    for command in commands:
        if command == "next":
            pos_sec += 10
            if total_sec < pos_sec:
                pos_sec = total_sec
        elif command == "prev":
            pos_sec -= 10
            if pos_sec < 0:
                pos_sec = 0
        if get_total_sec(op_start) <= pos_sec and pos_sec <= get_total_sec(op_end):
            pos_sec = get_total_sec(op_end)
            
    min = str(pos_sec // 60)
    if len(min) < 2:
        min = "0" + min
        
    sec = str(pos_sec % 60)
    if len(sec) < 2:
        sec = "0" + sec
        
    answer = min + ":" + sec
    
    return answer