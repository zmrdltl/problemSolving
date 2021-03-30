#include <bits/stdc++.h>
using namespace std;
int n,ans;
vector<pair<int, int>> v;
vector<int> d;
int main(){
    cin >> n;
    d.resize(n, 1);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[j].second < v[i].second){ // b가 증가 형태로 연결되어있으면
                if(d[j]+1 > d[i]){ //
                    d[i] = d[j] + 1;
                }
            }
        }
    }
    
    for(auto x : d) ans = max(ans,x);
    cout << n - ans <<'\n';
}