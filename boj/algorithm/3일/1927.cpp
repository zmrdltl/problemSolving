#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
priority_queue <int, vector<int>, greater<int>> minHeap;

int main(){
    fastio;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x) minHeap.push(x);
        else {
            if(!minHeap.size()) cout << 0;
            else cout << minHeap.top(),minHeap.pop();
            cout << '\n';
        }
    }
}