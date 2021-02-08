#include <bits/stdc++.h>
using namespace std;
int a[26],b[26];
int ans;
int main(){
    string word1, word2;
    cin >> word1 >> word2;
    for(int i = 0; i < word1.size(); i++) a[word1[i] - 'a']++;
    for(int i = 0; i < word2.size(); i++) b[word2[i] - 'a']++;
    for(int i = 0; i < 26; i++) ans += max(a[i], b[i]) - min(a[i], b[i]);
    cout << ans <<'\n';
}