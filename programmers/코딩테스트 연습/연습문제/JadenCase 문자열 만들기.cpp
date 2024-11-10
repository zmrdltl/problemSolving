#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(!cnt)
           if('a' <= s[i] && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            cnt = 1;
        }
        if(s[i] == ' ') cnt = 0;
        else cnt++;
    }
    return s;
}