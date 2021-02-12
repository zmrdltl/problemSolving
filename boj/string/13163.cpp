#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();

    while(n--){
        string s;
        string ans="";
        int cnt = 0;
        cin.clear();
        getline(cin,s);

        for(int i = 0; i < s.size(); i++){
            
            string tmp = "";
            int j = i;
            while(s[j] != ' ' && j != s.size())
                tmp += s[j++];
            i = j;
            if(!cnt) {
                ans += "god";
                cnt = 1;
                continue;
            }else{
                ans += tmp;
            }
        }
        cout << ans <<'\n';
    }

}