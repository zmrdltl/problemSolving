#include <bits/stdc++.h>
using namespace std;
const int MOD = 20170805;
vector<vector<int>> city;
int dist[501][501][3], M, N;

int dp(int m, int n, int dir){
    if(m == M - 1 && n == N - 1) return 1;
    if(m >= M || n >= N || city[m][n] == 1) return 0;
    int &ret = dist[m][n][dir];

    if(ret != -1) return ret;
    ret = 0;
    if(city[m][n] == 0){
        ret = (dp(m,n + 1, 1) + dp(m + 1,n,2)) % MOD;
    }
    if(city[m][n] == 2){
        if(dir == 1) ret = dp(m, n + 1, 1);
        if(dir == 2) ret = dp(m + 1, n, 2);
    }
    return ret % MOD;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    city = city_map;
    M = m, N = n;
    memset(dist,-1,sizeof(dist));
    return dp(0,0,0);
}