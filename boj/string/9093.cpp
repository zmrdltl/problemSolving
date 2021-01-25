#include <bits/stdc++.h>
using namespace std;
int t;
string getReversedWord(string word){
    string reversedWord = word;
    int size = reversedWord.size();
    for(int i = 0; i < size/2; i++){
        swap(reversedWord[i],reversedWord[size - 1-i]);
    }
    return reversedWord;
}

int main(){
    cin >> t;
    cin.ignore();
    while(t--){
        string sentence, ans = "";
        getline(cin,sentence);
        for(int pivot = 0; pivot < sentence.size(); pivot++){
            string word = "";
            while(sentence[pivot]!=' ' && pivot != sentence.size()){
                word += sentence[pivot++];
            }
            word = getReversedWord(word);
            ans += word + ' ';
        }
        cout << ans <<'\n';
    }
}