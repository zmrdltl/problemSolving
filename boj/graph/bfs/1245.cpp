//TODO
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, peekCnt;
int farm[101][101], ck[101][101];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

int isPeek(int s, int e){
    int p = 1;
    queue <pii> q;
    ck[s][e] = 1;
    q.push({s,e});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(farm[nx][ny] == 0 || ck[nx][ny]) continue;
            if(farm[nx][ny] > farm[s][e]) p = 0;
            ck[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    if(p) cout << s << ' ' << e << '\n';
    return p;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> farm[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(farm[i][j]){
                memset(ck,0,sizeof(ck));
                if(isPeek(i,j)) peekCnt++;

            }
        }
    }
    cout << peekCnt;
}