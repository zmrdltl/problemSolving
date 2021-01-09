#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <int> s;
    int k,ans=0;
    cin >> k;
    for(int i = 0; i < k; i++){
        int num;
        cin >> num;
        if(num) s.push(num);
        else s.pop();
    }
    while(!s.empty()){ 
        ans += s.top(); 
        s.pop(); 
    }
    cout << ans <<'\n';
}