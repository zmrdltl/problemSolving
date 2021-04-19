#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> graph[2001];
int ck[2001];
int dfs(int start,int cnt){
    //cout <<"start , cnt : " << start << ' ' << cnt << '\n';
    if(cnt == 5) return 1;
    if(ck[start]) return 0;
    ck[start] = 1;
    int ans = 0;
    for(int i = 0; i < graph[start].size(); i++){
        int next = graph[start][i];
        if(ck[next]) continue;
        ans = max(ans,dfs(next,cnt+1));
    }
    ck[start] = 0;
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 0; i < n; i++){
        memset(ck,0,sizeof(ck));
        ans = max(ans,dfs(i,1));
    }
    cout << ans <<'\n';   
}