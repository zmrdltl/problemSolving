#include <bits/stdc++.h>
using namespace std;

string getHead(string s){
    string tmp;
    string tmpS = s;
    for(int i = 0; i < tmpS.size(); i++){
        if('0' <= tmpS[i] && tmpS[i] <= '9') break;
        if('A' <= tmpS[i] && tmpS[i] <= 'Z') tmpS[i] = tmpS[i] - 'A' + 'a';
        tmp += tmpS[i];
    }
    return tmp;
}

string getNumber(string s){
    int idx = 0;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            idx = i;
            break;
        }
    }
    return s.substr(idx);
}


bool cmp(string a, string b){
    string aHead = getHead(a);
    string bHead = getHead(b);
    if(aHead == bHead){
        string aNum = getNumber(a);
        string bNum = getNumber(b);
        return stoi(aNum) < stoi(bNum);
    }
    return aHead < bHead;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),cmp);
    return files;
}