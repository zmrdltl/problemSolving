#include <iostream>
using namespace std;

int n,r,c,ans=0;

void fillBoard(int n,int x,int y){
    if(x == c && y == r){
        cout << ans;
        return;
    }
    if (y <= r && r < y + n && x <= c && c < x + n){
        fillBoard(n/2,x,y);
        fillBoard(n/2,x+n/2,y);
        fillBoard(n/2,x,y+n/2);
        fillBoard(n/2,x+n/2,y+n/2);
    }
    else ans += n*n;
}

int main(){
    cin >> n >> r >> c; // 2*n X 2*n의 판에서 (r,c)는 무슨 숫자?
    fillBoard(1<<n,0,0);
}
