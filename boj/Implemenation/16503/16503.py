import sys
input = sys.stdin.readline

def getRes(sa, op, sb):
  a = int(sa)
  b = int(sb)
  if(op == '+'): return a + b
  if(op == '-'): return a - b
  if(op == '*'): return a * b
  return -1*(abs(a)//abs(b)) if a*b < 0 else a//b

expr = input().split()

res1 = getRes(expr[0], expr[1], expr[2]);
res1 = getRes(str(res1), expr[3], expr[4]);

res2 = getRes(expr[2], expr[3], expr[4]);
res2 = getRes(expr[0], expr[1], str(res2));

print(min(res1, res2))
print(max(res1, res2))