#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
priority_queue <int, vector<int>> maxHeap;

int main(){
    fastio;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x) maxHeap.push(x);
        else {
            if(!maxHeap.size()) cout << 0;
            else cout << maxHeap.top(),maxHeap.pop();
            cout << '\n';
        }
    }
}