#include <bits/stdc++.h>
#define ONE_YEAR 365
using namespace std;
using pii = pair<int,int>;
int yearCnt[ONE_YEAR + 1], n, height, width, ans;
vector <pii> plan;

bool cmp(pii &a, pii &b){
    if(a.first == b.first){
        return a.second - a.first > b.second - b.first;
    }
    return a.first < b.first;
}

int main(){
    cin >> n;
    for(int i = 0,s,e; i < n; i++){
        cin >> s >> e;
        plan.push_back({s,e});
    }
    sort(plan.begin(),plan.end());

    for(auto p : plan)
        for(int j = p.first; j <= p.second; j++)
            yearCnt[j]++;

    for(int i = 1; i <= ONE_YEAR; i++){
        if(yearCnt[i]){
            height = max(height,yearCnt[i]);
            width++;
        }
        if(!yearCnt[i] || i == ONE_YEAR){
            ans += height * width;
            height = 0;
            width = 0;
        }
    }
    cout << ans;
}