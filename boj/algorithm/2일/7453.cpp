#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll nums[4001][4], n, ans;
vector <ll> sums1,sums2;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++) 
            cin >> nums[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sums1.push_back(nums[i][0]+nums[j][1]);
            sums2.push_back(nums[i][2]+nums[j][3]);
        }
    }

    sort(sums1.begin(),sums1.end());
    sort(sums2.begin(),sums2.end());


    for(int i = 0; i < sums1.size(); i++){
        int idx = lower_bound(sums2.begin(),sums2.end(),-sums1[i]) - sums2.begin();
        int endIdx = upper_bound(sums2.begin(),sums2.end(),-sums1[i]) - sums2.begin();
        ans += endIdx - idx;
    }

    cout << ans;
}