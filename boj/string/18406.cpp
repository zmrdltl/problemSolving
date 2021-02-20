#include <bits/stdc++.h>
using namespace std;
int a,b;
string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.size()/2; i++) a += s[i] -'0';
    for(int i = s.size()-1; i >= s.size()/2; i--) b += s[i] - '0';
    if(a==b) cout << "LUCKY\n";
    else cout << "READY\n";
}