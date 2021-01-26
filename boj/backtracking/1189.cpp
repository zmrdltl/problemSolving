#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char region[6][6];
int ck[6][6];
int r,c,k, ans;
void dfs(int x, int y, int distance){
    if(distance == k && x == 0 && y == c - 1) 
        {ans ++; return;}
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(region[nx][ny] == 'T') continue;
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(ck[nx][ny]) continue;
        ck[nx][ny] = 1;
        dfs(nx, ny, distance + 1);
        ck[nx][ny] = 0;
    }
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0 ;j < c; j++) 
            cin >> region[i][j];
    ck[r-1][0] = 1;
    dfs(r-1,0,1);   
    cout << ans <<'\n';
}