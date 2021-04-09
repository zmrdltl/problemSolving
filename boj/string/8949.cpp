#include <bits/stdc++.h>
using namespace std;
string a,b,ans;
int main(){
    cin >> a >> b;
    int diff = abs((int)a.size()- (int)b.size());
    if(a.size() > b.size()){
        for(int i = 0; i < diff; i++) ans += a[i];
        for(int i = 0; i < b.size(); i++){
            ans += to_string(a[i+diff] - '0' + b[i] - '0');
        }
    }else{
        for(int i = 0; i < diff; i++) ans += b[i];
        for(int i = 0; i < a.size(); i++){
            ans += to_string(b[i+diff] - '0' + a[i] - '0');
        }
    }
    cout << ans <<'\n';
}