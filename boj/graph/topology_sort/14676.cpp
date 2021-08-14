#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int indegree[100001], buildCheck[100001];
vector <int> graph[100001];
bool isCheat;
int main(){
    cin >> n >> m >> k;
    for(int i = 0,x,y; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    for(int i = 0,op,x; i < k; i++){
        cin >> op >> x;

        if(isCheat) continue;

        if(op == 1){ //°Ç¼³
            if(indegree[x]) isCheat = true;
            else{
                if(buildCheck[x]++) continue;
                for(auto next : graph[x]) indegree[next]--;
            }
        }

        else{
            if(buildCheck[x] == 0) isCheat = true;
            else {
                buildCheck[x]--;
                if(buildCheck[x] > 0) continue;
                for(auto next : graph[x]) indegree[next]++;
            }
        }

    }
    if(isCheat) cout << "Lier!";
    else cout << "King-God-Emperor";
}