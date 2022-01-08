t = int(input())

for i in range(t):
    num = int(input())
    ori = num
    print(num)
    while(num >= 100):
        sub = int(num % 10)
        num //= 10
        num -= sub
        print(num)
    if(ori % 11 == 0):
        print(f"The number {ori} is divisible by 11.")
    else:
        print(f"The number {ori} is not divisible by 11.")
    print()