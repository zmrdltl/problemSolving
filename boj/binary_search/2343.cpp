#include <bits/stdc++.h>
using namespace std;
int lesson[100001];
int maxLesson = 0;
int n,m;

int getBlueRayCount(int mid){
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += lesson[i];
        if(sum > mid) {
            i--;
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}

int binarySearch(){
    int left = maxLesson;
    int right = 1000000000;
    while(left <= right){
        int mid = (left + right)/2;
        int cnt = getBlueRayCount(mid);
        if(cnt >= m) left = mid + 1;
        else right = mid - 1; 
    }
    return left;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> lesson[i];
        maxLesson = max(maxLesson,lesson[i]);
    }
    cout << binarySearch();
}