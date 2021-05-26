#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000009
using namespace std;
ll t,n;
ll d[100001][4];

int main(){
    cin >> t;
    d[1][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;

    for(int i = 4; i <= 100000; i++){
        d[i][1] = (d[i-1][2] + d[i-1][3]) % MOD;
        d[i][2] = (d[i-2][3] + d[i-2][1]) % MOD;
        d[i][3] = (d[i-3][1] + d[i-3][2]) % MOD;
    }
    
    while(t--){
        cin >> n;
        cout << (d[n][1] + d[n][2] + d[n][3]) % MOD << '\n';
    }
}