#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
int n, l, a[5000001];
deque <pii> dq;

int main(){
    fastio;
    cin >> n >> l;
    for(int i = 0; i < n; i++) cin >> a[i];
    // 0 ~ l±îÁö
    for (int i = 0; i < n; i++){
        if (!dq.empty() && dq.front().second <= i - l) dq.pop_front();
        while (!dq.empty() && dq.back().first > a[i]) dq.pop_back();
        dq.push_back({a[i], i});
        cout << dq.front().first << ' ';
    }

}