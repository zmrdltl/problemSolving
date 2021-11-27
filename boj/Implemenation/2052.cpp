#include <bits/stdc++.h>
using namespace std;
int n;
double ans;
int main(){
    cin >> n;
    ans = pow(0.5,n);
    printf("%.*f",n,ans);
}