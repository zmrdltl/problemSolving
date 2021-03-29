#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans;
int main(){
    cin >> n;
    for(int k = 0; k < n; k++){
        ans += k * n + k;
    }
    cout << ans <<'\n';
}
