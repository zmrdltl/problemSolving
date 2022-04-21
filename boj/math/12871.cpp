#include <bits/stdc++.h>
using namespace std;
string s, t, ss, tt;
int lcmVal;

int GCD(int a, int b){
    if(!b) return a;
    return GCD(b, a%b);
}

int LCM(int a, int b){
    return a*b/GCD(a,b);
}

int main(){
    cin >> s >> t;
    lcmVal = LCM(s.size(), t.size());
    for(int i = 0; i < lcmVal / s.size(); i++) ss += s;
    for(int i = 0; i < lcmVal / t.size(); i++) tt += t;
    cout << (ss == tt);
}