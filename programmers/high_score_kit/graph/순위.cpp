#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int graph[101][101];
    memset(graph,0,sizeof(graph));

    for(auto &r : results)
        graph[r[0]][r[1]] = 1;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(graph[i][j] || graph[j][i])
                cnt++;
        if(cnt == n-1)
            answer++;
    }
    
    return answer;
}