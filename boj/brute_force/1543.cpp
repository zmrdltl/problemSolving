#include <bits/stdc++.h>
using namespace std;

string docs,searchWord;
int ans, cnt, wordSize;

int main(){

    getline(cin,docs);
    getline(cin,searchWord);

    for(int i = 0; i < docs.size(); i++){
        cnt = 0;
        wordSize = searchWord.size();

        if(docs[i] != searchWord[0]) continue;

        for(int j = i; j < i + wordSize; j++,cnt++)
            if(docs[j] != searchWord[j-i] ) 
                break;
        
        if(cnt == wordSize){
            ans++;
            i += wordSize-1;
        }
    }
    cout << ans;
}