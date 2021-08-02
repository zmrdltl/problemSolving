#include <bits/stdc++.h>
using namespace std;
int n, ck[10], digit[10] = {6,2,5,5,4,5,6,3,7,6}; 
string ans;
vector <int> v;

void dfs(int depth){
    if(depth == 4) {
        int cnt = 0;
        for(int i = 0; i < v.size(); i++) cnt += digit[v[i]];
        string hour = "";
        hour = to_string(v[0]) + to_string(v[1]);
        string minute = "";
        minute = to_string(v[2]) + to_string(v[3]);
        if(cnt == n && hour < "24" && minute < "60") ans = hour + ":" + minute;
        return;
    }

    for(int i = 0; i < 10; i++){
        v.push_back(i);
        dfs(depth + 1);
        v.pop_back();
    }
}

int main(){
    cin >> n;
    dfs(0);
    if(ans.size()) cout << ans;
    else cout << "Impossible";
}