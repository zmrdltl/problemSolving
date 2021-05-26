#include <bits/stdc++.h>
using namespace std;
int n,k;
vector <string> ans;

void backtracking(int depth, int m, int num, string prev){
    if(depth == m){
        if(!num) ans.push_back(prev.substr(1));
        return;
    }
    backtracking(depth + 1, m, num - 1, prev + "+1");
    backtracking(depth + 1, m, num - 2, prev + "+2");
    backtracking(depth + 1, m, num - 3, prev + "+3");
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        backtracking(0,i,n,"");
    }
    sort(ans.begin(),ans.end());
    if(ans.size() < k) cout << -1 << '\n';
    else cout << ans[k-1] << '\n';
}