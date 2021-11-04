#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;
int x, l, r, minDiff = MAX, ans = MAX;
int main(){
    cin >> x >> l >> r;
    for(int i = l; i <= r; i++){
        int diff = abs(i - x);
        if(minDiff > diff) {
            ans = i;
            minDiff = diff;
        }
    }
    cout << ans;
}