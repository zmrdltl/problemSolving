#include <bits/stdc++.h>
using namespace std;
int n, k, energy[21];

int bruteForce(int depth, int sum, int num){
    if(depth == n) return num;
    int ret = 0;
    ret = max(ret,bruteForce(depth+1,0,num));

    if(sum + energy[depth] >= k){
        int surplus = (sum + energy[depth]) - k;
        ret = max(ret,bruteForce(depth + 1, 0, num + surplus));
    }

    else ret = max(ret,bruteForce(depth+1, sum + energy[depth] , num));
    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> energy[i];
    cout << bruteForce(0,0,0);
}