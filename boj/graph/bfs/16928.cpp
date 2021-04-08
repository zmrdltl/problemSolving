//TODO
#include <bits/stdc++.h>
using namespace std;
using tpl = tuple<int,int,int>;
using pii = pair<int,int>;
int n, m;
vector <int> v[101];
int bfs(){
    int visited[101];
    int ans = 0x3f3f3f3f;
    queue <pii> q;
    q.push({1,0});
    visited[1] = 1;
    for(int i = 1; i <= 100; i++){
        if(!v[i].size())continue;
        if(v[i][0] % 6) q.push({v[i][0], v[i][0] / 6 + 1});
        else q.push({v[i][0], v[i][0] / 6});
    }

    while(!q.empty()){
        int start = q.front().first;
        int moved = q.front().second;
        q.pop();
        for(int i = 0; i < v[start].size(); i++){
            int next = v[start][i];
            if(visited[next])continue;
            visited[next] = 1;
            int dist = abs(start-next);
            int newMove;
            if(dist%6) newMove = dist / 6 + 1;
            else newMove = dist / 6;
            q.push({next ,newMove + moved});
            ans = min(ans,newMove + moved);
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