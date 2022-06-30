#include <bits/stdc++.h>
using namespace std;
int n, ans = 0x3f3f3f3f;
int snow[601];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> snow[i];
    sort(snow, snow + n);
    for(int i = 0; i < n; i++){
        for(int j = i+3; j < n; j++){
            int one = snow[i] + snow[j];
            int l = i + 1;
            int r = j - 1;
            while(l <= r){
                int two = snow[l] + snow[r];
                ans = min(ans, abs(one - two));
                if(one - two <= 0) r--;
                else l++;
            }
        }
    }
    cout << ans;
}