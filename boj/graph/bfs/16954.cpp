#include <bits/stdc++.h>
using namespace std;
using tpi = tuple<int,int>;
string chess[8];
int dr[] = {0,0,1,-1,-1,-1,1,1,0};
int dc[] = {1,-1,0,0,-1,1,-1,1,0};

void moveChess(){
    for(int i = 7; i >= 1; i--)
        chess[i] = chess[i-1];
    chess[0] = "........";
}

int bfs(){
    queue<tpi> q;
    q.push({7,0});
    while(!q.empty()){
        int qSize = q.size();

        while(qSize--){
            int r,c;
            tie(r,c) = q.front();
            q.pop();
            
            if(r == 0) return 1;

            for(int i = 0; i < 9; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0 > nr || nr >= 8 || 0 > nc || nc >= 8) continue;
                if(chess[nr][nc] == '#') continue;
                if(nr - 1 >= 0 && chess[nr - 1][nc] == '#') continue;
                q.push({nr,nc});
            } 
        }
        moveChess();
    }
    return 0;
}

int main(){
    for(int i = 0; i < 8; i++) cin >> chess[i];
    cout << bfs();
}