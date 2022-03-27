#include <bits/stdc++.h>
using namespace std;
int t, n, m, cnt;
int main(){
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> m;
        for(int i = n; i <= m; i++) {
            string num = to_string(i);
            for(int j = 0; j < num.size(); j++) 
                if(num[j] == '0') cnt++;
        }
        cout << cnt << '\n';
    }
}