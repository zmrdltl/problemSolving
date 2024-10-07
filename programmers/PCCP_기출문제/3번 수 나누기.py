number = int(input())

answer = 0

while number > 0:
    answer += number % 100
    number //= 100

print(answer)