#include <bits/stdc++.h>
using namespace std;
string s,t,ans;
int main(){
    cin >> s >> t;
    while(s.size() != t.size()){
        if(t[t.size()-1] == 'A') t.pop_back();
        else{
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
    if(s != t) cout << 0 << '\n';
    else cout << 1 << '\n';
}