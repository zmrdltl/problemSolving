#include <bits/stdc++.h>
using namespace std;
int l,c,ck[16];
char letter[16];
vector <char> candidates;
void dfs(int depth, int idx){
    if(depth == l) {
        int vowel = 0,consonant = 0;
        for(auto can : candidates){
            if(can == 'a' || can == 'e' || can == 'i' || can == 'o' || can == 'u') vowel++;
            else consonant++;
        }
        if(vowel < 1 || consonant < 2) return ;
        for(auto c : candidates) cout << c;
        cout << '\n';
        return;
    }
    for(int i = idx; i < c; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        candidates.push_back(letter[i]);
        dfs(depth + 1, i + 1);
        candidates.pop_back();
        ck[i] = 0;
    }
}

int main(){
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        cin >> letter[i];
    }
    sort(letter,letter + c);
    dfs(0,0);
}