#include <bits/stdc++.h>
using namespace std;
int n, b, i;
int main(){
    cin >> n;
    while(b <= n) {
        b += 2 * i * i + 2 * i + 1;
        i++;
    }
    cout << i - 1;
}