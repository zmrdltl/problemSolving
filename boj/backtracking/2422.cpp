#include <bits/stdc++.h>
using namespace std;
int n, m, ck[201], cnt;
vector <int> graph[201], comb, combCk;

bool isValid(int s, int e){
    for(auto next : graph[s]) {
        if(next == e) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0,a,b; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    combCk.resize(n, 1);
    for(int i = 0; i < 3; i++) combCk[i] = 0;
    do{
        int can = 1;
        vector<int> tmp;
        for(int i = 0; i < n; i++) {
            if(!combCk[i]) tmp.push_back(i+1);
        }

        for(int i = 0; i < 3; i++){
            for(int j = i + 1; j < 3; j++){
                if(!isValid(tmp[i], tmp[j])) { can = 0; break; }
            }
        }
        if(can) cnt++;
    }while(next_permutation(combCk.begin(), combCk.end()));
    cout << cnt;
}