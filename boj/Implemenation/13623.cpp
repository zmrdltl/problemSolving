#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    if(a == b && b == c) cout << '*';
    else if(a == b) cout << 'C';
    else if(a == c) cout << 'B';
    else if(b == c) cout << 'A';
}