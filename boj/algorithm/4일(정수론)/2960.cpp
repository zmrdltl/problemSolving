#include <bits/stdc++.h>
using namespace std;
int num[1001],ck[1001], n, k;

int eraseNum(){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!ck[i]){

            for(int j = i; j <= n; j+=i){
                if(!ck[j]){
                    cnt++;
                    if(cnt == k) return j;
                }
                ck[j] = 1;
            }
        }
    }
}
int main(){
    cin >> n >> k;
    for(int i = 2; i <= n; i++) num[i] = i;
    cout << eraseNum();
}