#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int main(){

    while(1){
        string s;
        getline(cin,s);
        if(s=="*")break;

        memset(alpha,0,sizeof(alpha));
        for(int i = 0; i < s.size(); i++){
            if('a' <= s[i] && s[i] <= 'z') alpha[s[i]-'a']++;
        }
        int flag = 0;
        for(int i = 0; i < 26; i++)
            if(!alpha[i]) 
                flag = 1;

        if(!flag) cout << "Y\n";
        else cout << "N\n";

    }
}