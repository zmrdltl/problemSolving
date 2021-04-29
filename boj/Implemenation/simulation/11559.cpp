#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
char board[12][6];
int ck[12][6];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int ans;
int boomed(int i, int j, char c){
    queue <pii> q;
    queue <pii> popQ;
    q.push({i,j});
    popQ.push({i,j});
    ck[i][j] = 1;
    int area = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= 12 || 0 > ny || ny >= 6) continue;
            if(ck[nx][ny] || board[nx][ny]!=c) continue;
            ck[nx][ny] = 1;
            q.push({nx,ny});
            popQ.push({nx,ny});
            area++;
        }
    }
    if(area>=4){
        while(!popQ.empty()){
            int x = popQ.front().first;
            int y = popQ.front().second;
            board[x][y] = '.';
            popQ.pop();
        }
    }
    return area;
}

void goDown(){
    queue <char> q;
    for(int j = 0; j < 6; j++){
        for(int i = 11; i >= 0; i--)
            if(board[i][j]!='.') 
                q.push(board[i][j]);
        for(int i = 11; i >= 0; i--) board[i][j] = '.';
        
        int piv = 11;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            board[piv--][j] = c;
        }
    }
}

int main(){
    for(int i = 0; i < 12; i++) cin >> board[i];
    while(1){
        int area = 0;
        memset(ck,0,sizeof(ck));

        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 6; j++)
                if(board[i][j]!='.')
                    area = max(area,boomed(i,j,board[i][j]));

        goDown();

        if(area < 4) break;
        else ans++;
    }
    cout << ans;
}