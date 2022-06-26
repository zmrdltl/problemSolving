#include <bits/stdc++.h>
using namespace std;
int t, ck[101][101];
string s;
vector<char>v;
map <string , int> m;
void dfs(int depth){
    if(depth == s.size()){
        string tmp;
        for(auto e : v) tmp+=e;
        m[tmp] = 1;
        return;
    }
    for(int i = 0; i < s.size(); i++){
        for(int j = i+1; j < s.size(); j++){
            swap(s[i],s[j]);
            dfs(depth+1);
            swap(s[i],s[j]);
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        m.clear();
        memset(ck,0,sizeof(ck));
        cin >> s;
        dfs(0);
        for(auto el : m) cout << el.first << '\n';
        cout << '\n';
    }
}