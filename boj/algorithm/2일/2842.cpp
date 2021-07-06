#include <bits/stdc++.h>
using namespace std;
char village[51][51];
int n, height[51][51], ck[51][51], houseCnt, startRow, startCol;
int dx[] = { 0,0,1,-1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,-1,1,1,-1 };
vector <int> h;

int dfs(int x, int y, int h1, int h2){
    //cout << x << ' ' << y << ' '<< h1 << ' ' << h2 << '\n';
    if(0 > x || x >= n || 0 > y || y >= n) return 0;
    if(ck[x][y] || height[x][y] > h1 || height[x][y] < h2) return 0;
    ck[x][y] = 1;
    int ret = (village[x][y] == 'K');

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret += dfs(nx,ny,h1,h2);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> village[i][j];
            if(village[i][j] == 'K') houseCnt++;
            if(village[i][j] == 'P') startRow = i, startCol = j;
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> height[i][j], h.push_back(height[i][j]);

    sort(h.begin(),h.end());
    int left = 0, right = 0;
    int ans = 1e+9;

    while(left < n * n ){
        memset(ck,0,sizeof(ck));
        if(dfs(startRow,startCol,h[left],h[right]) != houseCnt) left++;
        else{
            ans = min(ans, h[left] - h[right]);
            right++;
        }
    }
    cout << ans << '\n';
}