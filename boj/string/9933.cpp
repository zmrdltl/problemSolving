#include <bits/stdc++.h>
using namespace std;
int n;
string word[101];

string getOppositeWord(string w){
    string tmp = "";
    for(int i = 0; i < w.size(); i++){
        tmp += w[w.size()-1-i];
    }
    return tmp;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> word[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(word[i] == getOppositeWord(word[j])){
                int size = word[i].size();
                cout << size << ' ' << word[i][size/2]; 
                return 0;
            }
        }
    }
}