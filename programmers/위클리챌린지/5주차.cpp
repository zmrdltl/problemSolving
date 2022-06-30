#include <bits/stdc++.h>
using namespace std;
string str = "AEIOU";
map <string,int> comb;

void dfs(int depth, int want, string tmp){
    if(depth == want){
        comb[tmp] = 1;
        return;
    }
    for(int i = 0; i < 5; i++){
        dfs(depth + 1, want, tmp + str[i]);
    }
}

int solution(string word) {
    comb.clear();
    int answer = 0;
    
    for(int i = 1; i <= 5; i++) dfs(0,i,"");
    
    for(auto c : comb){
        answer++;
        if(c.first == word) return answer;
    }
    
    return answer;
}