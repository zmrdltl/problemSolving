#include <bits/stdc++.h>
using namespace std;
int n, dasom, ans;
priority_queue <int> pq;

int main(){
    cin >> n >> dasom;
    for(int i = 1, x; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    while(pq.size() && pq.top() >= dasom){
        int x = pq.top();
        pq.pop();
        ans++, dasom++;
        pq.push(x-1);
    }

    cout << ans;
}