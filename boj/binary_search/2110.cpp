#include <iostream>
#include <algorithm>
using namespace std;

//공유기 두 개 사이의 거리가 x 이상이 되게 할 수 있는가?
int binarySearch(int n, int c, int home[200001]){
    int r = home[n-1];
    int l = 1;
    int ans = 0;
    while(l<=r){
        int cnt = 1;
        int mid = (r+l)/2;
        int start = home[0];
        for(int i = 1; i < n; i++)
            if(home[i] - start >= mid) start = home[i],cnt++;
        if(cnt >= c) ans = mid, l = mid + 1;
        else  r = mid - 1;
    }
    return ans;
}

int main(){
    int n,c,MAX=0;
    int home[200001];
    cin >> n >> c;
    for(int i = 0; i < n; i++) 
        cin >> home[i];
    sort(home,home + n);
    cout << binarySearch(n,c,home);
}