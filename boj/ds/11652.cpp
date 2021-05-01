#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, maxNum;
map<ll,ll> m;
int main(){
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        m[x]++;
        maxNum = max(maxNum,m[x]);
    }
    for(auto &el : m){
        if(el.second == maxNum){
            cout << el.first;
            return 0;
        }
    }
}