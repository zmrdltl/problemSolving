#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;

int t, n, ans;
vector <pii> v;

int main(){
    fastio;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n);
        ans = 1;
        for(int i = 0; i < n; i++) 
            cin >> v[i].first >> v[i].second;
        sort(v.begin(),v.end());
        int minSecond = v[0].second;
        for(int i = 1; i < v.size(); i++)
            if(v[i].second < minSecond) 
                ans++, minSecond = v[i].second;
        cout << ans <<'\n';
    }
}