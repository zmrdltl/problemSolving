#include <bits/stdc++.h>
#define ll long long
using namespace std;
int treeNum, collectLength;
ll treeInfo[1000001];

ll binarySearch(){
    ll left = 0;
    ll right = 4000000000;
    while(left <= right){
        ll mid = (left + right) / 2;
        ll sum = 0;
        for(int i = 0; i < treeNum; i++){
            if(treeInfo[i] > mid) sum += treeInfo[i] - mid;
        }
        if(sum < collectLength) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

int main(){
    cin >> treeNum >> collectLength;
    for(int i = 0; i < treeNum; i++) cin >> treeInfo[i];
    sort(treeInfo,treeInfo + treeNum);
    cout << binarySearch();
}