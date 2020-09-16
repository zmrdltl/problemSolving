def convertStrToInt(strWord):
    tmp = []
    for i in range(strSize):
        tmp.append(ord(strWord[i])-96)
    return tmp

strSize = int(input())
strWord = input()
r = 1
M = 1234567891
h = 0

convertedWord = convertStrToInt(strWord)

for i in range(strSize):
    h += convertedWord[i] * r % M
    h %= M
    r*=31 % M
    
print(h)