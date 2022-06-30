#include <bits/stdc++.h>
using namespace std;
string s, t;
int ans = 0;

int dfs(string tmp){
    if(tmp == s) return 1;
    if(s.size() > tmp.size()) return 0;

    int ans = 0;

    if(tmp[tmp.size() - 1] == 'A'){
        tmp.pop_back();
        ans = max(ans,dfs(tmp));
        tmp.push_back('A');
    }
    if(tmp[0] == 'B'){
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        ans = max(ans, dfs(tmp));
    }
    return ans;
}

int main(){
    cin >> s >> t;
    cout << dfs(t);
}
