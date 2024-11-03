def solution(chicken):
    answer = 0
    coupon = chicken
    while coupon >= 10:
        answer += coupon // 10
        coupon = coupon // 10 + coupon % 10
    return answer