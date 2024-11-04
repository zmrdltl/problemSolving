def solution(friends, gifts):
    answer = 0
    gave_gift_dict = {}
    take_gift_dict = {}
    gift_index = {}
    get_gift_graph = {}
    checked = {}
    
    for f in friends:
        gave_gift_dict[f] = []
        take_gift_dict[f] = []
        gift_index[f] = 0
        get_gift_graph[f] = 0
        
    for f1 in friends:
        checked[f1] = {}
        for f2 in friends:
            checked[f1][f2] = False
            
    for g in gifts:
        splited_g = g.split()
        gave_gift_dict[splited_g[0]].append(splited_g[1])
        take_gift_dict[splited_g[1]].append(splited_g[0])
        
    for f in friends:
        gift_index[f] = len(gave_gift_dict[f]) - len(take_gift_dict[f])
    
    for f1_name in friends:
        for f2_name in friends:
            if checked[f1_name][f2_name]:
                continue
            checked[f1_name][f2_name] = True
            #f1이 f2에게 선물준 개수
            give_count = gave_gift_dict[f1_name].count(f2_name)
            #f2가 f1에게 선물준 개수
            take_count = take_gift_dict[f1_name].count(f2_name)
            # f1이 f2에게 선물준 개수가 더 많으면
            if give_count > take_count:
                get_gift_graph[f1_name] += 1
            elif give_count == take_count:
                if gift_index[f1_name] > gift_index[f2_name]:
                    get_gift_graph[f1_name] += 1
                
    for _, count in get_gift_graph.items():
        answer = max(answer,count)
    
    return answer