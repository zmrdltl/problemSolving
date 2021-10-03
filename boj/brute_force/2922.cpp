#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int sSize;
ll backtracking(ll depth, ll ja, ll mo, ll lexist){
    if(mo >= 3 || ja >= 3) return 0;
    if(depth == sSize) return lexist;
    ll ret = 0;
    if(s[depth] == '_'){
        ret += backtracking(depth + 1, ja + 1, 0, lexist) * 20;
        ret += backtracking(depth + 1, ja + 1, 0, 1);
        ret += backtracking(depth + 1, 0, mo + 1, lexist) * 5;
    }
    else {
        if(s[depth] == 'A' || s[depth] == 'E' || s[depth] == 'I' || s[depth] == 'O' || s[depth] == 'U')
            ret += backtracking(depth + 1, 0, mo + 1, lexist);
        else {
            if(s[depth] == 'L') ret += backtracking(depth + 1, ja + 1, 0, 1);
            else ret += backtracking(depth + 1, ja + 1, 0, lexist);
        }
    }
    return ret;
}
int main(){
    cin >> s;
    sSize = s.size();
    cout << backtracking(0,0,0,0);
}