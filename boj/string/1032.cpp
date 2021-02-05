#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string op[51];
    string ans = "";
    cin >> n;
    for(int i = 0; i < n; i++) cin >> op[i];
    for(int i = 0; i < op[0].size(); i++){
        int flag = 0;
        for(int j = 0; j < n - 1; j++){
            if(op[j][i] != op[j+1][i]) {
                flag = 1;
                break;
            }
        }
        if(flag) ans+="?";
        else ans += op[0][i];
    }
    cout << ans << '\n';
}