expression = input()
arr = expression.split('-')
ans = 0
parsedFirstExpArr = arr[0].split('+')

for i in range(0,len(parsedFirstExpArr)): 
    ans += int(parsedFirstExpArr[i]) 

for i in range(1,len(arr)):
    plus = arr[i].split('+')
    sum = 0
    for j in range(len(plus)):
        sum += int(plus[j])
    ans -= sum

print(ans)
