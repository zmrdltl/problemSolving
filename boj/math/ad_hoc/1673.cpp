#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    while(scanf("%d %d",&n,&k)!=EOF){
        int ans = 0,coupon = n,stamp = 0;
        while(coupon){
            ans += coupon;
            stamp += coupon;
            coupon = 0;
            coupon += stamp/k;
            stamp %= k;
        }
        cout << ans <<'\n';
    }
}