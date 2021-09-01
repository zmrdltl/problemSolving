#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue <int, vector<int>, greater<int>> pq;
int main(){
    scanf("%d",&n);
    for(int i = 0, x; i < n * n; i++){
        scanf("%d",&x);
        pq.push(x);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();
}