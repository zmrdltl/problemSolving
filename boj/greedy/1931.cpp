#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, ans, endTime = -1;

bool cmp (pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    cin >> n;
    vector <pii> conference(n);
    for(int i = 0; i < n; i++)
        cin >> conference[i].first >> conference[i].second;
    sort(conference.begin(),conference.end(),cmp);
    
    for(int i = 0; i < n; i++){
        if(endTime > conference[i].first) continue;
        ans++;
        endTime = conference[i].second;
    }
    cout << ans <<'\n';
}