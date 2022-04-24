#include <bits/stdc++.h>
using namespace std;
int t;
string convert(){
    int tmp = t;
    string s;
    while(tmp){
        s += to_string(tmp % 9);
        tmp /= 9;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    cin >> t;
    cout << convert();
}