#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, mid;
priority_queue <int,vector<int>> maxHeap;
priority_queue <int,vector<int>,greater<int>> minHeap;

int main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num; 
        cin >> num;
        if(maxHeap.size() == minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);
        if(minHeap.size() && maxHeap.size() && maxHeap.top() > minHeap.top()){
            int maxVal = maxHeap.top();
            int minVal = minHeap.top();
            maxHeap.pop(), minHeap.pop();
            minHeap.push(maxVal);
            maxHeap.push(minVal);
        }
        cout << maxHeap.top() << '\n';
    }
}