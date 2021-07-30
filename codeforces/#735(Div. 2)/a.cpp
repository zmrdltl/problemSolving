#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
int t;
ll a[100001];

int main(){
    fastio;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        ll n, ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++){
            ans = max(ans, a[i]*a[i+1]);
        }
        cout << ans << '\n';
    }
}