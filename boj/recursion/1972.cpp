#include <bits/stdc++.h>
using namespace std;
int check[100];
map<string,int> m;
vector<string> cnt[100];
string word;

bool isSuprising(){
    for(int i =1 ; i <= word.size(); i++){
        m.clear();
        for(int j = 0; j < cnt[i].size(); j++){
            if(m[cnt[i][j]]) return 0;
            else m[cnt[i][j]]++;
        }
    }
    return 1;
}

void backtracking(string word, string w, int idx, int level,int source){
    if(level==2){
        cnt[abs(idx-source)].push_back(w);
        return;
    }
    for(int i = idx; i < word.size(); i++){
        if(!check[i]){
            check[i] = 1;
            backtracking(word,w+word[i],i,level+1,idx);
            check[i] = 0;
        }
    }
}

int main(){
    while(1){
        cin >> word;
        memset(check,0,sizeof(check));
        memset(cnt,0,sizeof(cnt));
        if(word=="*")break;
        backtracking(word,"",0,0,0);
        if(isSuprising()){
            cout << word << " is surprising.\n";
        }else{
            cout << word << " is NOT surprising.\n";
        }
    }
}