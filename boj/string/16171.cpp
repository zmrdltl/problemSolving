#include <bits/stdc++.h>
using namespace std;
string s, k;
map <char, int> filteringMap;

string getFilteredString(){
    string filteredString;
    for(int i = 0; i < s.size(); i++)
        if(!filteringMap[s[i]]) 
            filteredString += s[i];
    return filteredString;
}

int main(){
    cin >> s >> k;
    for(int i = 0; i <= 9; i++) filteringMap[i + '0'] = 1;
    s = getFilteredString();
    if(s.find(k) != string::npos) cout << 1;
    else cout << 0;
}