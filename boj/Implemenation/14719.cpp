#include <bits/stdc++.h>
using namespace std;
//i번째 건물 오른쪽으로
//i번째 건물 왼쪽으로
int h, w, big, ans, world[501], d[501][2];
int main(){
    cin >> h >> w;
    for(int i = 1; i <= w; i++) cin >> world[i];
    big = world[1];
    for(int i = 2; i <= w; i++){
        if(big > world[i]) d[i][0] = big - world[i];
        else big = world[i];
    }
    big = world[w];
    for(int i = w - 1; i >= 1; i--){
        if(big > world[i]) d[i][1] = big - world[i];
        else big = world[i];
    }
    for(int i = 1; i <= w; i++) ans += min(d[i][0],d[i][1]);
    cout << ans;
}