#include <bits/stdc++.h>
using namespace std;
int t;

string getOppositeSentence(string sentence){
    int size = sentence.size();
    string ans = "";
    string tmp = "";
    vector <string> s;
    for(int i = 0; i < size; i++){
        tmp += sentence[i];
        if(sentence[i] == ' ' || i == size-1){
            s.push_back(tmp);
            tmp = "";
        }
    }
    for(int i = s.size() - 1; i >= 0; i--){
        ans += s[i];
        if(i == s.size() - 1) ans += ' ';
    }
    return ans;
}
int main(){
    cin >> t;
    cin.ignore();
    for(int i = 1; i <= t; i++){
        string sentence;
        getline(cin,sentence);
        sentence = getOppositeSentence(sentence);
        cout << "Case #" << i << ": " << sentence << '\n';
    }
}