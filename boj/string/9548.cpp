//TODO 
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int testCase;
string s;
void print(int w, int x){
    for(int i = w; i <= x; i++) cout << s[i];
    cout << '\n';
}
int main(){
    fastio;
    cin >> testCase;
    while(testCase--){
        cin >> s;
        while(1){
            string op, word;
            int x;
            cin >> op;
            if(op == "END") break;
            cin >> word >> x;
            if(op == "I"){
                cout << "WORD : " << word << ' ' << x << '\n';
                s = s.substr(0,x) + word + s.substr(x);
            }
            else{
                print(stoi(word),x);
            }
        }
    }
}