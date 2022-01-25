#include <bits/stdc++.h>
using namespace std;
int a, b, k;
int main(){
    cin >> a >> b >> k;
    cout << (a/k) * (b/k) - max(0, a/k - 2)*max(0, b/k - 2);
}