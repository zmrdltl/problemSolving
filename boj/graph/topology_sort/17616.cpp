#include <bits/stdc++.h>
using namespace std;
int n,m,x,ind[100001], cnt[100001], ck[100001];
vector <int> graph[100001];
queue <int> q;
map<int,int> rankMap;
int main(){
    cin >> n >> m >> x;
    for(int i = 0, a,b; i < m; i++){
        cin >> a >> b;
        ck[a] = ck[b] = 1;
        graph[a].push_back(b);
        ind[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(!ck[i] && i == x) { cout << 1 << ' ' << n << '\n'; return 0;}
    }
    for(int i = 1; i <= n; i++){
        if(!ind[i]) {
            rankMap[i] = 1;
            q.push(i);
        }
    }
    vector <int> ans;
    int rank = 1;
    for(int i = 1; i < n; i++){
        int qSize = q.size();
        rank++;
        while(qSize--){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto next : graph[x]){
                ind[next]--;
                if(!ind[next]){
                    rankMap[next] = rank;
                    q.push(next);
                }
            }
        }
    }
    for(auto el : rankMap) {
        cnt[el.second]++;
    }
    cout << rankMap[x] << ' ' << rankMap[x] + cnt[x] - 1;
    return 0;
}