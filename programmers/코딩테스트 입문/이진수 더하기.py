def to_decimal(bin):
    decimal = 0
    for num_char in bin:
        num = int(num_char)
        decimal = decimal * 2 + num
    return decimal 

def to_bin(decimal):
    bin = ""
    while decimal > 0:
        bin += str(decimal % 2)
        decimal = decimal // 2
    if not bin:
        return "0"
    return bin[::-1]

def solution(bin1, bin2):
    answer = ''
    return to_bin(to_decimal(bin1) + to_decimal(bin2))