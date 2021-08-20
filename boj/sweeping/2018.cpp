#include <bits/stdc++.h>
using namespace std;
int n,l=1,r=1,sum,ans;
int main(){
    cin >> n;
    while(l <= r && r <= n) {
        if(sum < n) sum += r++;
        else{
            if(sum == n) ans++;
            sum -= l++;
        }
    }
    cout << ans + 1;
}