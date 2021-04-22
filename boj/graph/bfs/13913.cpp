#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
int ck[100001], n, k;
vector <int> vec;

int bfs(){
    queue<pii> q;
    q.push({n,0});
    ck[n] = 1;
    
    while (!q.empty()) {
        int pos = q.front().first;
        int sec = q.front().second;
        q.pop();
        
        if(pos == k) return sec;
        
        if( pos + 1 < 100001 && ck[pos+1] == -1){
            ck[pos+1] = pos;
            q.push({pos+1, sec+1});
        }

        if( pos - 1 > -1 && ck[pos-1] == -1){
            ck[pos-1] = pos;
            q.push({pos-1, sec+1});
        }

        if( pos * 2 < 100001 && ck[pos*2] == -1){
            ck[pos*2] = pos;
            q.push({pos*2, sec+1});
        }
    }
}
int main(){
    fastio;
    memset(ck,-1,sizeof(ck));
    cin >> n >> k;
    
    cout << bfs() << '\n';
    vec.push_back(k);

    while (k != n) {
        vec.push_back(ck[k]);
        k = ck[k];
    }
    for(int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << " ";
}