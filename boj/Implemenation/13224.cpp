#include <bits/stdc++.h>
using namespace std;
int cup[4] {0,1,0,0};
string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') swap(cup[1],cup[2]);
        else if(s[i] == 'B') swap(cup[2],cup[3]);
        else swap(cup[1],cup[3]);
    }
    for(int i = 1; i <= 3; i++) if(cup[i]) { cout << i; break;}
}