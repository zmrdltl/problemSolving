#include <bits/stdc++.h>
using namespace std;
int n,k;
vector <string> ans;
void backtracking(int idx,int m,int num,string op){
    if(idx == m){
        if (num == n) ans.push_back(op.substr(1,op.size()-1));
        return;
    }
    backtracking(idx + 1, m, num + 1, op + "+1");
    backtracking(idx + 1, m, num + 2, op + "+2");
    backtracking(idx + 1, m, num + 3, op + "+3");
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) backtracking(0,i,0,"");
    sort(ans.begin(),ans.end());
    if(ans.size() >= k) cout << ans[k-1];
    else cout << "-1";
}