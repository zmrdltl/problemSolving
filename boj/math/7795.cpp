#include <bits/stdc++.h>
using namespace std;
int n, t;
int bs(int aElement, vector<int> &b){
    int l = 0;
    int r = b.size() - 1;
    int lowerBoundIdx = 0;
    while(l<=r){
        int mid = (l+r)/2;
        //aElementÀÇ lower_bound index Ã£±â
        if(aElement > b[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main(){
    cin >> t;
    while(t--){
        int aCnt,bCnt,ans = 0;
        cin >> aCnt >> bCnt;
        vector <int> a(aCnt);
        vector <int> b(bCnt);

        for(int i = 0; i < aCnt; i++) cin >> a[i];
        for(int i = 0; i < bCnt; i++) cin >> b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        for(int i = 0; i < aCnt; i++) ans += bs(a[i],b);
        cout << ans << '\n';
    }
}