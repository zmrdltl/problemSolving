#include <bits/stdc++.h>
using namespace std;
string s;
int maxPalinLen;

bool isPalindrome(string str){
    for(int i = 0; i < str.size() / 2; i++)
        if(str[i] != str[str.size() - 1 - i]) 
            return false;
    return true;
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(isPalindrome(s.substr(i))){
            maxPalinLen = max(maxPalinLen, (int)s.size() - i);
        }
    }
    
    cout << (s.size() - maxPalinLen) * 2 + maxPalinLen;
}