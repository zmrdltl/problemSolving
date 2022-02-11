#include <bits/stdc++.h>
using namespace std;
string word;
map <string,int> m;
vector <int> comb;
int main(){
    cin >> word;
    comb.resize(word.size(), 1);
    for(int i = 0; i < 2; i++) comb[i] = 0;
    do{
        vector<int>idx;
        string newWord = word;
        for(int i = 0; i < comb.size(); i++) {
            if(!comb[i]) idx.push_back(i);
        }

        if(abs(idx[0] - idx[1]) < 1 || !idx[0]) continue;
        reverse(newWord.begin() , newWord.begin() + idx[0]);
        reverse(newWord.begin()+idx[0] , newWord.begin() + idx[1]);
        reverse(newWord.begin()+idx[1] , newWord.end());
        m[newWord] = 1;
    }while(next_permutation(comb.begin(), comb.end()));
    cout << m.begin()->first;
}   