#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll r,c,n, maxi,mini;
int main(){
    cin >> r >> c >> n;
    maxi = max(r,c);
    mini = min(r,c);
    if(maxi % n) maxi = (maxi / n) + 1;
    else maxi /= n;
    if(mini % n) mini = (mini / n) + 1;
    else mini /= n;
    cout << maxi * mini << '\n';
}