#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
int t;
ll a[100001];
vector <pii> v;

int main(){
    fastio;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        v.clear();
        ll n, k, ans = -0x3f3f3f3f;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            //v.push_back({a[i],i});
        }
        //sort(v.begin(),v.end());
        
        for(int i = 1; i < n; i++){
            ans = max(ans, (i)*(i+1)- k * (a[i]|a[i+1]));
        }

        // for(int i = 0; i < n - 1; i++){
        //     ans = max(ans, (v[i].second)*(v[i+1].second)- k * (v[i].first|v[i+1].first));
        // }

        for(int i = 1; i <= n / 2; i++){
            ans = max(ans, (i)*(n-i+1)- k * (a[i]|a[n-i+1]));
        }

        for(int i = n; i > 1; i--){
            ans = max(ans, (1)*(i)- k * (a[1]|a[i]));   
        }

        for(int i = n-1; i >= 1; i--){
            ans = max(ans, (n)*(i)- k * (a[n]|a[i]));   
        }
        
        ans = max(ans ,(1)*(n) - k * (a[1]|a[n]));
        

        cout << ans << '\n';
    }
}