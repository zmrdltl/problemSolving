#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool finish;
    int child;
    Trie *alpha[26];
    Trie(): child(0) {
        memset(alpha,0,sizeof(alpha));
    }

    ~Trie(){
        for(int i = 0; i < 26; i++) delete alpha[i];
    }

    void insert(const char *str){
        if(*str == NULL) { child++; return;}
        int cur = *str - 'a';
        if(alpha[cur] == NULL){
            alpha[cur] = new Trie();
        }
        child++;
        alpha[cur]->insert(str+1);
    }

    int find(Trie *root, const char *target, int idx){
        if(*target == NULL || root->child == 1) return idx;
        int cur = *target - 'a';
        if(root->alpha[cur]){
            return find(root->alpha[cur], target+1,idx+1);
        }
    }


};

int solution(vector<string> words) {
    Trie *root = new Trie();
    int answer = 0;
    for(auto word : words){
        root->insert(word.c_str());
    }

    for(auto word : words){
        answer += root->find(root, word.c_str(), 0);
    }
    return answer;
}