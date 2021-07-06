#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fibo[91], n;
ll dp(int num){
    if(num == 1 || num == 2) return 1;
    ll &ret = fibo[num];
    if(ret) return ret;
    ret = 0;
    return ret = dp(num - 1) + dp(num - 2);
}

int main(){
    cin >> n;
    cout << dp(n);
}