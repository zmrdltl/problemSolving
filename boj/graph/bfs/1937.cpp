#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int,int,int>;

int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};
int bamboo[501][501], live[501][501], n, ans;

int dp(int r, int c){
    int &ret = live[r][c];
    if(ret) return ret;
    ret = 1;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(0 > nr || nr >= n || 0 > nc || nc >= n) continue;
        if(bamboo[r][c] >= bamboo[nr][nc]) continue;
        ret = max(ret,dp(nr, nc) + 1);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> bamboo[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans,dp(i,j));

    cout << ans;
}