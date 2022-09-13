import sys
input = sys.stdin.readline
a,b=map(int, input().split())
if a%b==0 :print( int (a/b))
else: print("%.10f"% (a/b))