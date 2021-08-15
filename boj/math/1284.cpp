#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    while(1){
        int width;
        cin >> s;
        if(s == "0") break;
        width = s.size() + 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') width += 2;
            else if(s[i] == '0') width += 4;
            else width += 3;
        }
        cout << width << '\n';
    }
}