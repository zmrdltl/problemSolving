#include <bits/stdc++.h>
using namespace std;
int leakPoint[1001];
int taped[1001];
int n, l, ans;
int main(){
    cin >> n >> l;  
    for(int i = 0; i < n; i++) cin >> leakPoint[i];
    sort(leakPoint,leakPoint+n);
    for(int i = 0; i < n; i++){
        if(!taped[leakPoint[i]]){
            for(int j = leakPoint[i]; j < min(leakPoint[i] + l, 1001); j++) taped[j] = 1;
            ans++;
        }
    }
    cout << ans <<'\n';
}