#include <bits/stdc++.h>
using namespace std;
int x,y,w,h,xbig,ybig;
int main(){
    cin >> x >> y >> w >> h;
    xbig = x <= w - x ? x : w - x;
	ybig = y <= h - y ? y : h - y;
	printf("%d", min(xbig,ybig));
}