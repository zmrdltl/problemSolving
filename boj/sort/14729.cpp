#include <bits/stdc++.h>
using namespace std;

int counting[100001], n, cnt;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        double score;
        cin >> score;
        counting[(int)(score*1000)]++;
    }

    for(int i = 0; i <= 100000; i++){
        if(!counting[i]) continue;
        if(cnt >= 7) break;
        while(counting[i]-- && cnt++ < 7){
            printf("%.3f\n", (double)i/1000);
        }
    }
}