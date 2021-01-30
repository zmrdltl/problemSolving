#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int area[101][101];
int safeArea[101][101];
int check[101][101];
int n, ans;

void immerseArea(int n, int waterHeight){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(waterHeight < area[i][j]) safeArea[i][j] = 1;
        }
    }
}

void bfs(int i,int j){
    queue <pair<int,int>> q;
    q.push({i,j});
    check[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >=n) continue;
            if(!safeArea[nx][ny]) continue;
            if(!check[nx][ny]){
                check[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> area[i][j];

    for(int waterHeight = 0; waterHeight <= 100; waterHeight++){
        memset(safeArea,0,sizeof(safeArea));
        memset(check, 0, sizeof(check));
        immerseArea(n, waterHeight);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!check[i][j] && safeArea[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans <<'\n';
}