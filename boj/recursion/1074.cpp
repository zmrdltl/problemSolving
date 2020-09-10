#include <iostream>
#include <cmath>
using namespace std;
int n,r,c,ans=0;
int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

void fillBoard(int n,int x,int y){
    if(n==2){
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx== r && ny == c){
                cout << ans;
                return;
            }
            ans++;
        }
        return;
    }
    fillBoard(n/2,x,y);
    fillBoard(n/2,x,y+n/2);
    fillBoard(n/2,x+n/2,y);
    fillBoard(n/2,x+n/2,y+n/2);
}

int main(){
    cin >> n >> r >> c; // 2*n X 2*n의 판에서 (r,c)는 무슨 숫자?
    fillBoard(1<<n,0,0);
}