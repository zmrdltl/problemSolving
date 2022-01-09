def sum(num):
	return num * (num + 1) // 2
n = int(input())
for i in range(1,n+1):
	a, b = map(int, input().split())
	print("Scenario #%d:"%(i))
	print(sum(b)-sum(a-1))
	print()
