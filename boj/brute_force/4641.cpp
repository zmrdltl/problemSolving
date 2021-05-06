#include <bits/stdc++.h>
using namespace std;
vector <int> num;
int ans;

int main(){
    while(1){
        int x;
        cin >> x;
        if(x == -1) break;
        if(x) {num.push_back(x); continue;}
        for(int i = 0; i < num.size(); i++)
            for(int j = 0; j < num.size(); j++)
                if(num[i] == num[j] * 2) 
                    ans++;
        cout << ans << '\n';
        num.clear();
        ans = 0;
    }
}