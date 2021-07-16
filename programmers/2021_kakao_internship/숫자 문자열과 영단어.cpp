#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    map<string,int> m;
    m["zero"] = -1;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;

    string answer = "";
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        tmp += s[i];
        if('0' <= s[i] && s[i] <= '9'){
            answer+= s[i];
            tmp = "";
        }
        else if(m[tmp]){
            if(tmp == "zero") answer += '0';
            else answer += to_string(m[tmp]);
            tmp = "";
        }
    }
    return stoi(answer);
}