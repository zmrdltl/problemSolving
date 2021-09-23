#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
int n, testCase, d[100001][2];

int main(){
    cin >> testCase;
    d[1][1] = d[2][1] = d[2][0] = d[0][0] = 1;
    for(int i = 3; i <= 100000; i++) {
        d[i][0] = ((d[i-1][1] + d[i-2][1]) % MOD + d[i-3][1]) % MOD;
        d[i][1] = ((d[i-1][0] + d[i-2][0]) % MOD + d[i-3][0]) % MOD;
    }
    while(testCase--){
        cin >> n;
        cout << d[n][1] << ' ' << d[n][0] << '\n';
    }
}