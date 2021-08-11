#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using pii = pair<int,int>;
int n, ans = 1;
vector <pii> v;
int main(){
    fastio;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end());

    priority_queue <int,vector<int>,greater<int>> pq;
    pq.push(v[0].second);
    for(int i = 1; i < n; i++){
        int startPoint = v[i].first;
        int endPoint = v[i].second;

        while(pq.size() && pq.top() <= startPoint) pq.pop();
        pq.push(endPoint);
        ans = max(ans,(int)pq.size());
    }
    cout << ans << '\n';
}
