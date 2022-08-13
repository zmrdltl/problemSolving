#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    while(1){
        getline(cin,s);
        if(s == "***") break;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}