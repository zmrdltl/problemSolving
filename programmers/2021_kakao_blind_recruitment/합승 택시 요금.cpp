#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
ll charge[201][201], N, ans;

void initCharge(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            charge[i][j] = INF;
        }
    }
}

void makeChargeMatrix(vector<vector<int>> fares){
    for(int i = 0; i < fares.size(); i++){
        charge[fares[i][0]][fares[i][1]] = fares[i][2];
        charge[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i = 1; i <= N; i++) charge[i][i] = 0;
}

void makeFloyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j || j == k || i == k) continue;
                charge[i][j] = min(charge[i][j],charge[i][k] + charge[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    initCharge();
    makeChargeMatrix(fares);
    makeFloyd();
    ans = charge[s][a] + charge[s][b];

    for(int i = 1; i <= N; i++){
        //n까지 동승해서 흩어지는 것이 기존 따로 가는 것보다 작다면
        ans = min(ans,charge[s][i] + charge[i][a] + charge[i][b]);
    }

    return (int)ans;
}