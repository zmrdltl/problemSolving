#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        int cnt = 0, piv = 0;
        string s, ans="";
        string twoWords=" ";
        getline(cin,s);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') cnt++;
            if(cnt == 2) {piv = i + 1; break;}
            twoWords += s[i];
        }
        for(int i = piv; i < s.size(); i++){
            cout << s[i];
        }
        cout << twoWords <<'\n';
    }
}