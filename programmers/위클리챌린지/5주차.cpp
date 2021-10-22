#include <bits/stdc++.h>
using namespace std;
vector <string> dictionary;
string allChar = "AEIOU";
map <string,int> m;
bool cmp(string a, string b){
    for(int i = 0; i < a.size(); i++)
        if(a[i] < b[i] && i < b.size()) 
            return a[i] < b[i];
    return (int)a.size() < (int)b.size();
}

void dfs(int depth, string word, int limit){
    if(depth == limit){
        m[word] = 1;
        return;
    }
    for(int i = 0; i < 5; i++) dfs(depth + 1, word + allChar[i], limit);
}

int solution(string word) {
    int answer = 1;
    dictionary.clear();
    m.clear();
    for(int i = 1; i <= 5; i++)
        dfs(0,"",i);

    for(auto el : m) dictionary.push_back(el.first);

    for(auto d : dictionary) {
        if(d == word) return answer;
        answer++;
    }
}