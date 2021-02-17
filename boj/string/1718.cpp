#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    string ans="";
    getline(cin,a);
    cin.clear();
    cin >> b;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(i+j >= a.size()) break;
            if(a[i+j] == ' ') {ans += ' '; continue;}
            int password = (a[i+j] -'0') - (b[j] -'0');
            if(password > 0){
                ans += password + 'a' - 1;
            }else{
                ans += 26 + password + 'a' - 1;
            }
        }
        i += b.size() - 1;
    }
    cout << ans <<'\n';
}