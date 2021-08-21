#include <bits/stdc++.h>
using namespace std;

bool isRightBracket(string s){
    stack <char> st;
    if(s == "" || s[0] == ')') return false;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else{
            if(st.size() && st.top() == '(') st.pop();
            else return false;
        }
    }
    if(st.size()) return false;
    return true;
}

bool isBalanced(string w){
    int l = 0,r = 0;
    for(int i = 0; i < w.size(); i++){
        if(w[i] == '(') l++;
        else r++;
    }
    return l == r;
}

string getOpposite(string s){
    string tmp = s;
    for(int j = 0; j < s.size(); j++){
        if(tmp[j] == '(') tmp[j] = ')';
        else tmp[j] = '(';
    }
    return tmp;
}

string dfs(string w){
    if(w == "") return "";
    if(isRightBracket(w)) return w;
    string newW;
    for(int i = 1; i <= w.size(); i++){
        string u = w.substr(0, i);
        string v = w.substr(i);
        if(!isBalanced(u) || !isBalanced(v)) continue;

        if(!isRightBracket(u)){
            string tmp = "";
            tmp += '(' + dfs(v) + ')';
            string tmp2 = u.substr(1, u.size()-2);
            tmp2 = getOpposite(tmp2);
            newW = tmp + tmp2;
        }
        else newW = u + dfs(v);
        
        if(isRightBracket(newW)) return newW;
    }
    return newW;
}

string solution(string p) {
    string answer = "";
    return dfs(p);
}