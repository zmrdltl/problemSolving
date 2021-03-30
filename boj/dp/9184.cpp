#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int a,b,c;
int d[101][101][101];
int w(int a,int b, int c){
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    int &ret = d[a+50][b+50][c+50];
    if(ret !=-1) return ret;
    if (a > 20 || b > 20 || c > 20) return ret = w(20,20,20);
    if (a < b && b < c) return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return ret;
}

int main(){
    fastio;
    memset(d,-1,sizeof(d));
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && a == b && b == c) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
    }
}