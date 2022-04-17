#include <bits/stdc++.h>
using namespace std;
int t, k;
string ans;
vector <string> words;

bool isPalindrome(string mergedWord){
    int sz = mergedWord.size();
    for(int i = 0; i < sz / 2; i++)
        if(mergedWord[i] != mergedWord[sz - i - 1]) 
            return false;
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> k;
        ans = "0";
        words.resize(k);
        for(int i = 0; i < k; i++) cin >> words[i];

        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                string mergedWord = words[i] + words[j];
                string mergedWord2 = words[j] + words[i];
                if(isPalindrome(mergedWord)) ans = mergedWord;
                if(isPalindrome(mergedWord2)) ans = mergedWord2;
            }
        }
        cout << ans << '\n';
    }
}