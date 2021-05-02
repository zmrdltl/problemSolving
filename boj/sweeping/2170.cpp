#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using pii = pair<int,int>;
int n, ans, startPoint, endPoint;

int main(){
    fastio;
    cin >> n;
    vector <pii> point(n);
    for(auto &p : point) cin >> p.first >> p.second;
    sort(point.begin(),point.end());
    startPoint = point[0].first;
    endPoint = point[0].second;
    for(int i = 1; i < n; i++){
        if(endPoint < point[i].first){ //선 안겹치는 경우
            ans += endPoint - startPoint;
            startPoint = point[i].first;
            endPoint = point[i].second;
        }
        else endPoint = max(endPoint,point[i].second); //선 겹치는 경우
    }
    ans += endPoint - startPoint;
    cout << ans << '\n';
}
