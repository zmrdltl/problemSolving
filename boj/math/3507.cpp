#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    if(n > 198) cout << 0;
    else cout << 99 - (n - 99) + 1;
}