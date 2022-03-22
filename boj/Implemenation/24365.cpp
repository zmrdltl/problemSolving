#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector <pii> v(3);
int ans, avg;
int main(){
    v[0].second = 0; v[1].second = 1; v[2].second = 2;
    cin >> v[0].first >> v[1].first >> v[2].first;
    avg = (v[0].first + v[1].first + v[2].first) / 3;
    sort(v.begin(), v.end());
    cout << abs(v[2].second - v[0].second) * (avg - v[0].first) + abs(v[2].second - v[1].second) * (avg - v[1].first);
}