#include <bits/stdc++.h>
#define NM 10000000
using namespace std;
int l;
int main(){
    while(cin >> l){
        int n;
        int length = l * NM;
        cin >> n;
        vector <int> lego(n);
        for(int i = 0, x; i < n; i++) cin >> lego[i];
        sort(lego.begin(),lego.end());
        int isFind = 0;
        for(int i = 0; i < n; i++){
            int key = length - lego[i];
            int idx = lower_bound(lego.begin(), lego.end(), key) - lego.begin();
            if(i != idx && lego[idx] == key) {
                isFind = 1;
                cout << "yes " << lego[i] << ' ' << lego[idx] << '\n';
                break;
            }
        }
        if(!isFind) cout << "danger\n";
    }
}