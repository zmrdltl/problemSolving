#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, ans;
map<ll,vector<ll>> m;
int main(){
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s.size()].push_back(i);
    }

    for(auto &el : m){
        vector<ll> v = el.second;
        sort(v.begin(),v.end());
        for(ll i = 0; i < v.size(); i++){
            ans += upper_bound(v.begin(),v.end(),v[i]+k) - (v.begin() + i + 1);
            //cout << "el. , ans : " << el.first  << ' ' << ans <<'\n';
        }
    }

    cout << ans <<'\n';

}