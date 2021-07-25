#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,m, startRow, startCol, ck[601][601];
char campus[601][601];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

string bfs(){
    int ans = 0;
    queue <pii> q;
    q.push({startRow, startCol});
    ck[startRow][startCol] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(campus[nx][ny] == 'X' || ck[nx][ny]) continue;
            if(campus[nx][ny] == 'P') ans++;
            ck[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    if(!ans) return "TT";
    return to_string(ans);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I') startRow = i, startCol = j;
        }
    }
    cout << bfs();
}