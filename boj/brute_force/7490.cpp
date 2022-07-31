#include <bits/stdc++.h>
using namespace std;
int t, n;

int getEval(string s){
    string tmpS, tmpNum;

    for(auto c : s)
        if(c != ' ') tmpS += c;

    vector <int> num;
    vector <char> op;

    for(auto t : tmpS){
        if(t == '-' || t == '+') {
            op.push_back(t);
            num.push_back(stoi(tmpNum));
            tmpNum = "";
            continue;
        }
        tmpNum += t;
    }

    num.push_back(stoi(tmpNum));
    int ans = num[0];
    for(int i = 1; i < num.size(); i++){
        if(op[i-1] == '+') ans += num[i];
        else ans -= num[i];
    }
    return ans;
}

void dfs(int depth, string s){
    if (depth == n){
        if(!getEval(s)) cout << s << '\n';
        return;
    }
    dfs(depth+1, s + ' ' + to_string(depth + 1));
    dfs(depth+1, s + '+' + to_string(depth + 1));
    dfs(depth+1, s + '-' + to_string(depth + 1));
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        dfs(1, "1");
        cout << '\n';
    }
}
