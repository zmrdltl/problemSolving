def solution(lines):
    answer = 0
    overlap = []
    
    for i, x in enumerate(lines):
        for j, x2 in enumerate(lines):
            if i == j:
                continue
            if x2[0] <= x[1] and x[0] <= x2[1]:
                min_val = max(x[0], x2[0]) 
                max_val = min(x[1], x2[1]) 
                overlap.append([min_val, max_val])
    
    if not overlap:
        return 0
    
    overlap.sort()
    
    current_start, current_end = overlap[0]
    for i in range(1, len(overlap)):
        start, end = overlap[i]
        if start <= current_end:
            current_end = max(current_end, end)
        else:
            answer += current_end - current_start
            current_start, current_end = start, end
    
    answer += current_end - current_start
    return answer
