#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
ll n;

mat mulMatrix(mat &a, mat & b){
    mat tmp(2,vector<ll>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }
    return tmp;
}

int main(){
    cin >> n;
    mat ans = {{{0,1},{1,0}}};
    mat a = {{1,1},{1,0}};
    while(n > 0){
        if(n & 1) ans = mulMatrix(a,ans);
        a = mulMatrix(a,a);
        n /= 2;
    }   
    cout << ans[0][0];
}