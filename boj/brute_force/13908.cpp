#include <bits/stdc++.h>
using namespace std;
int n, m, know[10];
vector <char> v;
vector <int> ans;
void dfs(int depth){
    if(depth == n){
        string tmp = "";
        for(int i = 0; i < 10; i++){
            if(know[i]){
                int flag = 0;
                for(auto e : v){
                    if(e - '0' == i) {flag = 1; break;}
                }
                if(!flag) return;
            }
        }
        for(auto e : v) tmp += e;
        ans.push_back(stoi(tmp));
        return;
    }
    for(int i = 0; i <= 9; i++){
        v.push_back(i + '0');
        dfs(depth + 1);
        v.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0, x; i < m; i++){
        cin >> x;
        know[x] = 1;
    }
    dfs(0);
    cout << ans.size();
}