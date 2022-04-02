#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans = 4, fibo[81];

ll getFibo(ll x){
    if(x == 1 || x == 2) return fibo[x] = 1;
    ll &ret = fibo[x];
    if(ret != -1) return ret;
    return ret = getFibo(x-1) + getFibo(x-2);
}

int main(){
    memset(fibo, -1, sizeof(fibo));
    cin >> n;

    for(int i = 2; i <= n; i++){
        ll length = getFibo(i);
        ans += length * 2;
    }
    
    cout << ans;
}