#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int solution(string s){
    int answer=0;
    int cnt = 0;
    for(int l = 1; l <= s.size(); l++){
        for(int i = 0; i < s.size(); i++){
            string tmp ="";
            for(int j = i; i+l <= s.size() && j < i+l; j++){
                tmp += s[j];
            }
            int size = tmp.size();
            if(isPalindrome(tmp)) answer = max(answer,size);
        }
    }

    return answer;
}