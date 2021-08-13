#include <bits/stdc++.h>
using namespace std;
string s;

bool isPalindrome(){    
    for(int i = 0; i < s.size() / 2; i++)
        if(s[i] != s[s.size() - 1 - i]) 
            return false;
    return true;
}

bool isAllSame(){
    map <char,int> alphaMap;
    for(int i = 0; i < s.size(); i++) alphaMap[s[i]] = 1;
    return alphaMap.size() == 1;
}

int main(){
    cin >> s;
    if(isAllSame()) { cout << -1; return 0; }
    if(isPalindrome()) {cout << s.size() - 1; return 0;}
    cout << s.size();
}