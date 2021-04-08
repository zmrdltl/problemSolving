#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m;
vector <int> v[101];
int bfs(){
    int visited[101];
    memset(visited,0,sizeof(visited));
    int ans = 0x3f3f3f3f;
    queue <pii> q;
    q.push({1,0}); //현재 위치, 주사위 던진 횟수
    
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int moved = q.front().second;
        if(x == 100) {ans = min(ans, moved); break;}
        q.pop();
        for(int i = 1; i <= 6; i++){
            int nx = x + i;
            if(nx > 100 || visited[nx]) continue;
            visited[nx] = 1;
            if(!v[nx].size()) q.push({nx,moved + 1});
            else q.push({v[nx][0],moved + 1});
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
    }
    cout << bfs() << '\n';
}