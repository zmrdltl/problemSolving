#include <bits/stdc++.h>
using namespace std;
string n, ans;
int m;
int main(){
    cin >> n;
    cin >> m;
    for(int i = 0; i < stoi(n); i++)
        ans += n;
    if(m < ans.size()){
        for(int i = 0; i < m; i++)
            cout << ans[i];
    }
    else{
        for(int i = 0; i < ans.size(); i++) 
            cout << ans[i];
    }

}