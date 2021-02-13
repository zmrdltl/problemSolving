#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string word){
    string tmp = "";
    for(int i = 0; i < word.size(); i++){
        if('A' <= word[i] && word[i] <= 'Z'){
            tmp += word[i] - 'A' + 'a';
        }else
            tmp += word[i];
    }
    return tmp;
}

bool isPalindrome(string word){
    for(int i = 0; i < word.size()/2; i++){
        if(word[i] != word[word.size()-1-i]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string word;
        cin.clear();
        getline(cin,word);
        word = toLowerCase(word);
        if(isPalindrome(word)) cout << "Yes\n";
        else cout << "No\n";
    }
}