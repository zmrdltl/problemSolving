#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int n,m,t;
int scc[MAX];
int indegree[MAX];
bool ck[MAX];

vector <int> graph[MAX];
vector <int> revGraph[MAX];
vector <int> sccStat[MAX];

stack <int> st;

//dfs 수행하며 //끝나면 역추적하면서 정점 저장
void dfs(int cur){
    ck[cur] = true;
    for(auto &g : graph[cur]){
        int next = g;
        if(ck[next]) continue;
        dfs(next);
    }
    st.push(cur); 
}

void updateSCC(int cur, int idx){
    scc[cur] = idx; //현재 scc번호 저장

    for(auto &rg : revGraph[cur]){
        int next = rg;
        if(scc[next] == 0) updateSCC(next,idx); //연결 된 next에 해당하는 scc값이 없다면 같은 SCC 번호로 속하게해줌
        else if(scc[next] != scc[cur]) { //서로 다른 블록이라면
            indegree[scc[cur]]++;
            //SCC끼리의 연결 상태 저장 
            //*주의점*  revGraph는 역방향 그래프이므로
            //            SCC끼리의 연결상태를 저장할 때 현재SCC -> 다른 SCC로 연결상태를 저장하면 안되고
            //            원래 연결상태를 생각해서 다른 SCC -> 현재 SCC 로 연결상태를 저장해줘야한다.
            sccStat[scc[next]].push_back(scc[cur]);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            revGraph[v].push_back(u); //역방향 그래프
        }

        for(int i = 1; i <= n; i++){
            if(ck[i]) continue;
            dfs(i);
        }

        int idx = 1;
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            if(scc[cur]) continue; //이미 SCC에 속한 블록이라면 pass
            scc[cur] = idx; //속하지 않았다면  해당 블록에 scc 번호 저장
            updateSCC(cur,idx); //다음 정점에 대해 scc update
            idx++; //다음 scc번호를 위해 증가
        }

        int result = 0;
        for(int i  = 1; i < idx; i++) if(!indegree[i]) result++; //진입차수가 0인 정점은 손가락으로 밀어줘야한다.
        cout << result << '\n';

        //초기화
        for(int i = 1; i <= n; i++){
            scc[i] = 0;
            indegree[i] = 0;
            ck[i] = false;
            graph[i].clear();
            revGraph[i].clear();
            sccStat[i].clear();
        }
    }
}