#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int d[201][201], adj[201][201];

    for(int i = 0; i <= 200; i++)
        for(int j = 0; j <= 200; j++)
            d[i][j] = INF;
    vector <int> graph[201];
    for(auto e : edge_list){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    d[0][gps_log[0]] = 0;

    for(int i = 1; i < k; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = min(d[i][j], d[i-1][j]);
            for(auto node : graph[j]){
                d[i][j] = min(d[i][j], d[i-1][node]);
            }
            if(gps_log[i] != j){
                d[i][j]++;
            }
        }
    }

    if(d[k-1][gps_log[k-1]] >= INF) return -1;
    return d[k-1][gps_log[k-1]];
}