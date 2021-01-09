#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum = 0;
    int ans = 0;
    int score[10];
    for(int i = 0; i < 10; i++) cin >> score[i];
    for(int i = 0; i < 10; i++){
        sum += score[i];
        int sumGap = abs(100 - sum);
        int ansGap = abs(100 - ans);
        if(sumGap < ansGap) ans = sum;
        else if(sumGap==ansGap) ans = max(ans,sum);
    }
    cout << ans <<'\n';
}