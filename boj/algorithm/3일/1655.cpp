#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;
int n;
priority_queue <int,vector<int>> maxHeap;
priority_queue <int,vector<int>,greater<int>> minHeap;
int main(){
    fastio;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(maxHeap.size() == minHeap.size()) { maxHeap.push(x);}
        else minHeap.push(x);
        if(minHeap.size() && maxHeap.top() > minHeap.top()){
            int v1 = maxHeap.top();
            int v2 = minHeap.top();
            maxHeap.pop(), minHeap.pop();
            maxHeap.push(v2), minHeap.push(v1);
        }
        cout << maxHeap.top() << '\n';
    }
}