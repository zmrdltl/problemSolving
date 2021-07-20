#include <bits/stdc++.h>
using namespace std;
int n;
int liquid[100001];
void twoPointer(){
    int l = 0, r = n - 1;
    int a,b;
    int sum = INT_MAX;
    while(l<r){
        int tmpSum = liquid[l] + liquid[r];

        if(abs(sum) > abs(tmpSum)) {
            sum = tmpSum;
            a = liquid[l];
            b = liquid[r];
        }

        if(tmpSum == 0) break;
        else if(tmpSum > 0) r--;
        else l++;
    }   
    cout << a << ' ' << b;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> liquid[i];
    twoPointer();
}