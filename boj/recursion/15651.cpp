#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> v;

void dfs(int depth){
    if(depth == m){
        for(auto num : v) cout << num << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        v.push_back(i);
        dfs(depth+1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    dfs(0);
}