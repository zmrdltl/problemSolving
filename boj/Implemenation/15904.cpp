#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int idx;
int main(){
    getline(cin,s);
    
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='U' && !cnt)
            cnt = 1;
        if(s[i] == 'C'){
            if(cnt == 1) cnt = 2;
            if(cnt == 3){
                cnt = 4; 
                break; 
            }
        }
        if(s[i]=='P')
            if(cnt == 2) cnt = 3;
    }
    if(cnt == 4) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";
}