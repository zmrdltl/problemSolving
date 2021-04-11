#include <bits/stdc++.h>
using namespace std;
int n, score;
string s;
int main(){
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++){
        score += s[i]-'A' + 1;
    }
    cout << score <<'\n';
}