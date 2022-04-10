#include <bits/stdc++.h>
using namespace std;

map <char, int> vowelMap;
string s;

bool conditionOne(){
    bool isVowel = false;
    for(int i = 0; i < s.size(); i++)
        if(vowelMap[s[i]]) 
            isVowel = true;
    return isVowel;
}

bool conditionTwo(){
    int vowelCnt = 0, consonantCnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(vowelMap[s[i]]) consonantCnt = 0, vowelCnt++;
        else vowelCnt = 0, consonantCnt++;
        if(vowelCnt == 3 || consonantCnt == 3) return false;
    }
    return true;
}

bool conditionThree(){
    char prev = s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] == prev && (s[i] != 'e' && s[i] != 'o')) return false;
        prev = s[i];
    }
    return true;
}

string getString(){
    bool isValid = conditionOne() && conditionTwo() && conditionThree();
    if(isValid) return "acceptable.\n";
    return "not acceptable.\n";
}

int main(){
    vowelMap['a'] = 1, vowelMap['i'] = 1;
    vowelMap['e'] = 1, vowelMap['o'] = 1, vowelMap['u'] = 1;

    while(1){
        cin >> s;
        if(s == "end") break;
        cout << '<' << s << '>' << " is " << getString();
    }

}