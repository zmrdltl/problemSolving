#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int ck[100001],n,k;
priority_queue <pii,vector<pii>,greater<pii>> pq;
int bfs(){
    if(n>k) return n-k;
    int ans = 0x3f3f3f3f;
    pq.push({0,n});
    ck[0] = 1;
    
    while(!pq.empty()){
        int x = pq.top().second;
        int sec = pq.top().first;
        pq.pop();
        if(x == k) return sec;
        if(x*2 <= 100000 && !ck[x*2]){
            ck[x*2] = 1;
            pq.push({sec,x*2});
        }
        if(x+1 <= 100000 && !ck[x+1]){
            ck[x+1] = 1;
            pq.push({sec+1,x+1});
        }
        if(x-1 >= 0 && !ck[x-1]){
            ck[x-1] = 1;
            pq.push({sec+1,x-1});
        }
    }
}

int main(){
    cin >> n >> k;
    cout << bfs();
}