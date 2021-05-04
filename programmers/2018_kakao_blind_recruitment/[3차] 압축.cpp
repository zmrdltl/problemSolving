#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map <string,int> m;
    int cnt = 0, piv = 0;
    string w ="";
    for(int i = 0; i < 26; i++){
        string s(1,'A' + i);
        m[s] = ++cnt;
    }
    for(int i = 0; i < msg.size(); i++){
        string w(1,msg[piv]);
        for(int j = piv + 1; j < msg.size(); j++){
            if(m[w + msg[j]]) w += msg[j];
            else{
                answer.push_back(m[w]);
                piv = j;
                m[w+msg[j]] = ++cnt;
                break;
            }
        }
    }
    string surplus = msg.substr(piv);
    if(m[surplus]) answer.push_back(m[surplus]);
    else answer.push_back(++cnt);
    return answer;
}
