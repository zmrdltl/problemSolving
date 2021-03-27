#include <bits/stdc++.h>
using namespace std;
string s;
int n,bonus,score;
int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'X') bonus = 0;
        else score += i + 1 + bonus++;
    }
    cout << score <<'\n';
}