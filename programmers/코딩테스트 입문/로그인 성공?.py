def solution(id_pw, db):
    is_same = {'id': False, 'pw': False}
    same_id = False
    same_pw = False
    for i in range(0, len(db)):
        data = db[i]
        
        if id_pw[0] == data[0] and id_pw[1] == data[1]:
            is_same['id'] = True
            is_same['pw'] = True
            break
        if id_pw[0] == data[0] and id_pw[1] != data[1]:
            is_same['id'] = True
            is_same['pw'] = False
            break
        
    if is_same['id'] and is_same['pw']:
        return 'login'
    if is_same['id'] and not is_same['pw']:
        return 'wrong pw'
    return 'fail'