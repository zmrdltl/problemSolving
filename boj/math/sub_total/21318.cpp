#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, t, piv, score[100001], d[100001];

int main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> score[i];
    for(int i = 1; i <= n; i++){
        if(score[i] > score[i+1]) piv++;
        d[i+1] = piv;
    }
    cin >> t;
    while(t--){
        int start,end;
        cin >> start >> end;
        cout << d[end] - d[start] <<'\n';
    }
}