#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> num, v;
int ck2[10001][10];
int ck[10001];
void backtracking(int depth){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(ck[i] || ck2[num[i]][depth]) continue;
        ck[i] = 1;
        ck2[num[i]][depth] = 1;
        v.push_back(num[i]);
        backtracking(depth + 1);
        v.pop_back();
        ck[i] = 0;
    }

    for(int i = 0; i < n; i++){
        ck2[num[i]][depth] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0,x; i < n; i++){
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    backtracking(0);
}