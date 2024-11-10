#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;

int solution(int n, vector<int> money) {
    int d[100001];
    memset(d,0,sizeof(d));
    d[0] = 1;
    for(auto &coin : money){
        for(int i = 0; i <= n; i++){
            if(i- coin >= 0) d[i] += d[i-coin] % MOD;
        }
    }
    return d[n];
}