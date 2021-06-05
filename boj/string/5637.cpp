#include <bits/stdc++.h>
using namespace std;
vector <string> v;
int main(){
    string s;
    int maxLength = 0;
    while(1){
        cin >> s;
        if(s == "E-N-D") break;
        string tmp;
        for(int i = 0; i < s.size(); i++)
            if(('a'<=s[i]&&s[i]<='z') || s[i] == '-' || ('A'<=s[i]&&s[i]<='Z')) 
                tmp += s[i];
        v.push_back(tmp);
    }
    for(auto el: v) {
        int cnt = 0;
        for(int i = 0; i < el.size(); i++) cnt++;
        maxLength = max(maxLength, cnt);
    }
    for(auto el : v) if(el.size() == maxLength) {
        for(auto w : el){
            if('A' <= w && w <= 'Z') printf("%c",w - 'A'+'a');
            else cout << w;
        }
        return 0;
    }
}