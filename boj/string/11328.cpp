#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    while(n--){
        string a,b;
        int flag = 0;
        int alpha1[26] = {0}, alpha2[26] ={0};
        cin >> a >> b;
        for(int i = 0; i < a.size(); i++) alpha1[a[i]-'a']++;
        for(int i = 0; i < b.size(); i++) alpha2[b[i]-'a']++;
        for(int i = 0; i < 26; i++)
            if(alpha1[i] != alpha2[i]) {flag = 1; break;}
        if(flag) cout << "Impossible\n";
        else cout << "Possible\n";
    }
}