#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string ans;
int main(){
    cin >> n;
    while(n){
        ans += to_string(n % 2);
        n /= 2;
    }
    for(int i = ans.size() - 1; i >= 0; i-- ){
        cout << ans[i];
    }
}