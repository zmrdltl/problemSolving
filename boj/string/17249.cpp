#include <bits/stdc++.h>
using namespace std;
string s;
int l,r,piv;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')')  {piv = i; break;}
        if(s[i] == '@') l++;
    }
    for(int i = piv + 1; i < s.size(); i++){
        if(s[i]=='@') r++;
    }
    cout << l << ' ' << r << '\n';
}