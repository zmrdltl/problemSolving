#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
int main(){
    cin >> s;
    for(auto c : s) ans += pow(c - '0',5);
    cout << ans;
}