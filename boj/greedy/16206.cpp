#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
vector <int> ten, notTen;

void cutCake(int length){
    if(m <= 0 || length < 10) return;
    m--, ans++, length -= 10;
    if (length > 10) cutCake(length);
    else if (length == 10) ans++;
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0,x; i < n; i++) {
        cin >> x;
        if(x % 10) notTen.push_back(x);
        else ten.push_back(x);
    }

    sort(notTen.begin(),notTen.end());
    sort(ten.begin(),ten.end());

    for(auto t : ten){
        if(t == 10) ans++;
        else cutCake(t);
    }

    for(auto nt : notTen) cutCake(nt);
    cout << ans << '\n';
}