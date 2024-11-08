def solution(wallet, bill):
    answer = 0
    wallet.sort()
    bill.sort()
    while wallet[0] < bill[0] or wallet[1] < bill[1]:
        bill[1] //= 2
        answer += 1
        bill.sort()
    return answer