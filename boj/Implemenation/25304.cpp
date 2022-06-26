#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll totalPrice, t, sum, a, b;
int main(){
    cin >> totalPrice >> t;
    while(t--){
        cin >> a >> b;
        sum += a * b;
    }
    if(totalPrice == sum){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}