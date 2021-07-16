#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1001], b[1001], n, m, ans = 1;
vector <ll> gcds, el;


ll gcd(ll num, ll num1){
    if(num1 == 0 ) return num;
    return gcd(num1,num % num1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            gcds.push_back(gcd(a[i],b[j]));
        }
    }

    for(int i = 0; i < gcds.size(); i++) {
        cout << gcds[i] << ' ',ans *= gcds[i];
    }
    cout << ans << '\n';
    
}