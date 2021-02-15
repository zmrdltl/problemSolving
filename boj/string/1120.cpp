#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int ans = 0x3f3f3f3f;
    for(int i = 0; i <= b.size() - a.size(); i++){
        int cnt = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] != b[j+i]) cnt++;
        }
        ans = min(ans,cnt);
    }
    cout << ans <<'\n';
}