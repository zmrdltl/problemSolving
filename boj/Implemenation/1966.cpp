#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int n,m,ans=0;
        queue <pair<int,int>> printerQ;
        priority_queue <int> pq;
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            int imp;
            cin >> imp;
            printerQ.push({i,imp});
            pq.push(imp);
        }

        while(!printerQ.empty()){
            int page = printerQ.front().first;
            int importance = printerQ.front().second;
            printerQ.pop();
            if(pq.top()==importance){
                pq.pop();
                ans++;
                if(page == m) {
                    cout << ans << '\n';
                    break;
                }
            }
            else printerQ.push({page,importance});
        }
    }
}