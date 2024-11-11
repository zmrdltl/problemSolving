def solution(bandage, health, attacks):
    health_limit = health
    cure_time, cure_amount_per_sec, bonus_cure = bandage
    for i in range(len(attacks)):
        attack_time, attack_damage = attacks[i]
        health -= attack_damage
        if health <= 0:
            return -1
        if i == len(attacks) - 1:
            break
        time_left_for_next_attack = attacks[i+1][0] - attack_time - 1
        health += time_left_for_next_attack * cure_amount_per_sec
        health += time_left_for_next_attack // cure_time * bonus_cure
        if health > health_limit:
            health = health_limit
            
    return health