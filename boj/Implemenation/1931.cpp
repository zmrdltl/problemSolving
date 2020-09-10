#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int ans;
vector <pair<int,int>> v(100000);

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second) return a.first<b.first;
    return a.second < b.second;
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.begin() + n,cmp);
    int endTime = -1;
    for(int i = 0; i < n; i++){
        //시작 시간이 같은 회의들 중 가장 일찍 끝나는 시간을 고른다.
        if(endTime>v[i].first) continue;
        else endTime = v[i].second,ans++;
    }
    cout << ans <<'\n';
}