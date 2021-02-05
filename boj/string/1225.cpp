#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
string a, b;
int main(){
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            ans += (ll)(a[i] - '0') * (ll)(b[j] - '0');
    cout << ans <<'\n';
}