#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        ll n, oddSum = 0, evenSum = 0;
        cin >> n;
        vector <ll> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(auto el : nums) {
            if(el % 2) oddSum += el;
            else evenSum += el;
        }
        if(evenSum > oddSum) cout << "EVEN\n";
        else if(evenSum == oddSum) cout << "TIE\n";
        else cout << "ODD\n";
    }
}