#include <bits/stdc++.h>
using namespace std;
struct Trie {
    int count;
    bool finish;    //끝나는 지점을 표시해줌
    Trie* next[26];    //26가지 알파벳에 대한 트라이
    Trie() : finish(false), count(1) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }
    void insert(const char* key) {
        if (*key == '\0')
            finish = true;    //문자열이 끝나는 지점일 경우 표시
        else {
            int curr = *key - 'a';
            if (next[curr] == NULL)
                next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
            else next[curr]->count++;
            next[curr]->insert(key + 1);    //다음 문자 삽입
        }
    }
    int find(const char* key) {
        int curr = *key - 'a';
        if(*key == '?'){
            int tmp = 0;
            for(int k = 0; k < 26; k++){
                if(next[k] != NULL) tmp += next[k]->count;
            }
            return tmp;
        }
        if (next[curr] == NULL) return 0;//찾는 값이 존재하지 않음
        if(*(key + 1) == '?') return next[curr]->count;
        return next[curr]->find(key + 1); //다음 문자를 탐색
    }
};

Trie *root[10001];
Trie *reroot[10001];

 
vector<int> solution(vector<string> words, vector<string> queries) {
    int qsize = queries.size();
    vector<int> answer(qsize, 0);
    for (auto &a : words){
        int size = a.size();
        const char *c = a.c_str();
        if (root[size] == NULL) root[size] = new Trie();
        root[size]->insert(c);
        string reversed_string = a;
        reverse(reversed_string.begin(), reversed_string.end());
        const char *k = reversed_string.c_str();
        if (reroot[size] == NULL) reroot[size] = new Trie();
        reroot[size]->insert(k);
    }
 
    int idx = 0;
    for (auto &a : queries){
        int size = a.size();
        if (a[size - 1] == '?'){
            const char *c = a.c_str();
            if (root[size] == NULL){ idx++; continue; }
            else answer[idx] = root[size]->find(c);
        }
        else{
            string re = a;
            reverse(re.begin(), re.end());
            const char *k = re.c_str();
            if (reroot[size] == NULL){ idx++; continue; }
            else answer[idx] = reroot[size]->find(k);
        }
        idx++;
    }
 
    return answer;
}

