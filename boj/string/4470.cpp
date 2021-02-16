#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin,s);
        cin.clear();
        printf("%d. ",i);
        cout << s <<'\n';
    }
}