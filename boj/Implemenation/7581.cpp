#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int zeroIdx, val = 1;
        vector <int> len(4);

        for(int i = 0; i < 4; i++) {
            cin >> len[i];
            if(!len[i]) zeroIdx = i;
        }

        if(!len[0] && !len[1] && !len[2] && !len[3]) break;

        for(int i = 0; i < 3; i++) if(len[i]) val *= len[i];

        if(len[3]) val = len[3] / val; 

        for(int i = 0; i < 4; i++) {
            if(i == zeroIdx) cout << val << ' ';
            else cout << len[i] << ' ';
        }
        cout << '\n';
    }
}