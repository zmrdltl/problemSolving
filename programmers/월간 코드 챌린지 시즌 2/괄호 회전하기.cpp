#include <bits/stdc++.h>

using namespace std;

string rotateString(string s){
    string tmp = "";
    tmp += s[s.size()-1];
    tmp += s.substr(0,s.size()-1);
    return tmp;
}

int isRightBracket(string s){
    stack <char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else{
            if(st.empty()) return 0;
            if(!st.empty() && st.top()=='(' && s[i] == ')') st.pop();
            if(!st.empty() && st.top()=='{' && s[i] == '}') st.pop();
            if(!st.empty() && st.top()=='[' && s[i] == ']') st.pop();
        }
    }
    if(st.empty()) return 1;
    return 0;
}

int solution(string s) {
    int answer = 0;
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(isRightBracket(s)) answer++;
        s = rotateString(s);
    }
    return answer;
}