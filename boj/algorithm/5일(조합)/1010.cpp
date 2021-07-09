#include <bits/stdc++.h>
using namespace std;
int t;
int comb[31][31];

int dfs(int n, int k){
    if(n == k || k == 0) return 1;
    int &ret = comb[n][k];
    if(ret) return ret;
    ret = dfs(n-1,k) + dfs(n-1,k-1);
    return ret; 
}

int main(){
    cin >> t;
    while(t--){
        int n, m;
        memset(comb,0,sizeof(comb));
        cin >> n >> m;
        cout << dfs(m,n) << '\n';
    }
}