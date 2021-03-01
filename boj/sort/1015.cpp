#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001],b[1001],ck[1001];
vector <int> answer;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b + n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == b[j] && !ck[j]){
                ck[j] = 1;
                answer.push_back(j);
                break;
            }
        }
    }
    for(auto p : answer) cout << p << ' ';
}