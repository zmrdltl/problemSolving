#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
using ll = long long;
ll n, ans;
int main(){
    cin >> n;
    if(n % 2){
        cout << max(n % MOD,n / 2 * (n / 2 + 1) % MOD);
    }
    else cout << max(n % MOD,n / 2 * n / 2 % MOD);
}