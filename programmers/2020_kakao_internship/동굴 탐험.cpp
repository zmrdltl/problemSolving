#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <int> graph[200001];
vector <int> oneDirGraph[200001];
vector <int> visit;
vector <int> finish;
bool answer = true;
void dfs(int start){
    if(answer == false) return;
    visit[start] = 1;
    for(auto next : oneDirGraph[start]){
        if(!visit[next]) dfs(next);
        else if(!finish[next]) {answer = false; return;}
    }
    finish[start] = 1;
    return;
}


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(int i = 0; i <= 200000; i++) graph[i].clear();
    for(auto p : path){
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }

    queue <int> q;
    q.push(0);
    visit.assign(n,0);
    visit[0] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto g : graph[now]){
            if(visit[g]) continue;
            visit[g] = 1;
            oneDirGraph[now].push_back(g);
            q.push(g);
        }
    }

    for(auto o: order){
        if(!o[1]) return false;
        oneDirGraph[o[0]].push_back(o[1]);
    }

    visit.assign(n,0);
    finish.assign(n,0);
    dfs(0);

    return answer;
}