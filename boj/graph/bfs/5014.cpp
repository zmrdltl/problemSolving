#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int f,s,g,u,d;
int ck[1000001];
int bfs(){
    queue <pii> q;
    q.push({s,0});
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(x == g) return cnt;
        if(!ck[x+u] && x + u <= f){
            ck[x + u] = 1, q.push({x + u, cnt+1});
        }
        if(!ck[x - d] && x - d >= 1){
            ck[x - d] = 1, q.push({x - d, cnt+1});
        }
    }
    return -1;
}

int main(){
    cin >> f >> s >> g >> u >> d;
    int ans = bfs();
    if(ans == -1) cout << "use the stairs";
    else cout << ans;
}