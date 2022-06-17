#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k, q, m, s, e, ans;
vector <int> student;
map <int,int> sleep, attend;
int main(){
    fastio;
    cin >> n >> k >> q >> m;
    student[2] = 0;
    for(int i = 0, x; i < k; i++) {
        cin >> x;
        sleep[x] = 1;
    }
    for(int i = 0, x; i < q; i++) {
        cin >> x;
        attend[x] = 1;
    }
    
    for(auto a : attend){
        int tmp = a.first;
        if(sleep[tmp]) continue;
        for(int i = 1; tmp <= n+2; i++){
            if(!sleep[tmp])
                student[tmp] = 0;
            tmp = i*a.first;
        }
    }
    
    for(int i = 3; i <= n+2; i++){
        student[i] += student[i-1];
    }

    for(int i = 0; i < m; i++){
        cin >> s >> e;
        cout << student[e] - student[s-1] << '\n';
    }
}