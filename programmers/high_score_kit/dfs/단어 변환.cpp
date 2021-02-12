#include <bits/stdc++.h>
using namespace std;
int answer = 0x7f7f7f7f;
 
void dfs(string begin, string target, vector<string> words, int check[], int cnt = 0) {
    for (int i = 0; i < words.size(); i++) {
        int count = 0;
        for (int j = 0; j < words[i].size(); j++)
            if (!check[i] && begin[j] != words[i][j])    count++;
        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            check[i] = true;
            dfs(words[i], target, words, check, cnt + 1);
            check[i] = false;
        }
    }
}
 
int solution(string begin, string target, vector<string> words) {
    int check[51];
    memset(check,0,sizeof(check));
    dfs(begin, target, words, check);
    if (answer == 0x7f7f7f7f)   return 0;
    return answer;
}