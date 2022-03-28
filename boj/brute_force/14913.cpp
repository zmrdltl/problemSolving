#include <bits/stdc++.h>
using namespace std;
int a, d, k, ans;
bool isValid;
int main(){
    cin >> a >> d >> k;
    for(int i = 1; i <= 1000000; i++){
        if(a + (i - 1) * d == k) { 
            isValid = true; 
            ans = i; 
            break;
        }
    }
    if(isValid) cout << ans;
    else cout << "X";
}