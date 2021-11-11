#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    if(n % 2) cout << "Either";
    else {
        if(n * (n+1) / 2 % 2) cout << "Odd";
        else cout << "Even";
    }
}