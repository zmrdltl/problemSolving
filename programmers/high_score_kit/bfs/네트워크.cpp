#include <bits/stdc++.h>

using namespace std;
void bfs(int x, int ck[], vector<vector<int>> &computers){
    queue <int> q;
    q.push(x);
    ck[x] = 1;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(int next = 0; next < computers[num].size(); next++){
            if(computers[num][next] && !ck[next]){
                q.push(next);                
                ck[next] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int ck[201];
    memset(ck,0,sizeof(ck));
    for(int i = 0; i < computers.size(); i++){
        if(!ck[i]){
            bfs(i,ck,computers);
            answer++;
        }
    }
    return answer;
}