#include <bits/stdc++.h>
using namespace std;
string s;
map <char, int> m;
int convert() {
    int num = 0;
    int indice = s.size() - 1;
    for(int i = 0; i < s.size(); i++, indice--) 
        num += pow(8,indice) * m[s[i]];
    return num;
}
int main(){
    m['-'] = 0, m['\\'] = 1, m['('] = 2, m['@'] = 3;
    m['?'] = 4, m['>'] = 5, m['&'] = 6, m['%'] = 7;
    m['/'] = -1;
    while(1){
        cin >> s;
        if(s == "#") break;
        cout << convert() << '\n';
    }
}