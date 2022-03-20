#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string stringN = to_string(i);
        int sum = 0;
        for(int j = 0; j < stringN.size(); j++){
            sum += stringN[j] - '0';
        }
        if(i % sum == 0) ans++;
    }
    cout << ans;
}