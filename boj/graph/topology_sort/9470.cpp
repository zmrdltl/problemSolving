#include <bits/stdc++.h>
using namespace std;
int t, ind[1001], orderCnt[1001][1001], k, m, p;

struct Strahler{
    int max, order;
};

int main(){
    cin >> t;
    while(t--){
        memset(ind,0,sizeof(ind));
        memset(orderCnt,0,sizeof(orderCnt));

        cin >> k >> m >> p;
        vector<vector<int>> graph(m + 1);
        for(int i = 0, a, b; i < p; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            ind[b]++;
        }

        queue <int> q;
        vector <Strahler> info(m + 1);
        for(int i = 1; i <= m; i++){
            if(!ind[i]) q.push(i), info[i].order = 1;
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(auto next : graph[cur]){
                ind[next]--;
                info[next].max = max(info[next].max, info[cur].order);
                orderCnt[next][info[cur].order]++;

                if(!ind[next]){
                    if(orderCnt[next][info[next].max] == 1){
                        info[next].order = info[next].max;
                    }
                    else if(orderCnt[next][info[next].max] > 1){
                        info[next].order = info[next].max + 1;
                    }
                    q.push(next);
                }
            }
        }
        cout << k << ' ' << info[m].order << '\n';
    }
}