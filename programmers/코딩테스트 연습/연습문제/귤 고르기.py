def solution(k, tangerine):
    answer = 0
    tangerine_map = {}
    for t in tangerine:
        tangerine_map[t] = tangerine_map.get(t,0) + 1
    tangerine_map = sorted(tangerine_map.items(), key = lambda x: x[1], reverse=True)
    sum = 0
    for _, num in tangerine_map:
        answer += 1
        sum += num
        if sum >= k:
            break
    
    return answer