#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            if('A' <= s[i] && s[i] <= 'Z') 
                s[i] = s[i]-'A'+'a';
        cout << s <<'\n';
    }
}