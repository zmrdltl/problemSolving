//0번쨰부터 i번쨰의 사람들의 합
//j번쨰에 우체국을 만들었다고 가정시
//0번쨰에서 j번 위치까지 사람들 합 = sum[j]
//j+1 ~ n-1위치까지 사람들 합 = sum[n-1] - sum[j]

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
vector <pair<int,int>>x;
vector<ll> sum;

ll binarySearch(){
    int l = 0;
    int r = n-1;
    int pos = 0x7f7f7f7f;
    while(l<=r){
        int mid = (l+r)/2;
        ll leftSum = sum[mid];
        ll rightSum = sum[n - 1] - sum[mid];
        if(leftSum >= rightSum){
            r = mid - 1;
            pos = min(pos, x[mid].first);
        }else{
            l = mid + 1;
        }
    }
    return pos;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        int pos, peopleNum;
        cin >> pos >> peopleNum;
        x.push_back({pos,peopleNum});
    }
    sort(x.begin(),x.end());

    sum.push_back( x[0].second);
    for(ll i = 1; i < n; i++){
        sum.push_back(sum[i-1] + x[i].second);
    }
    cout << binarySearch();
    

}