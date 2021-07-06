#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[100001], s;

ll twoPointer(){
    ll ans = n + 1;
    ll sum = a[0];
    ll l = 0, r = 0;
    while(l <= r && r < n){
        if(sum < s) sum += a[++r];
        else if(sum == s) {
            ans = min(ans, r - l + 1);
            sum += a[++r];
        }
        else{
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    if(ans > n) return 0;
    return ans;
} 
int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << twoPointer();
}