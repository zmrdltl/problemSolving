import sys
def findPreffix(phoneBook):
    for i in range(len(phoneBook)-1):
        if phoneBook[i] == phoneBook[i+1][0:len(phoneBook[i])]:
            return "NO"
    return "YES"

t = int(input())
while t:
    t-=1
    phoneBook = []
    n = int(input())
    for i in range(n):
        phoneBook.append(sys.stdin.readline().strip())
    phoneBook.sort()
    print(findPreffix(phoneBook))