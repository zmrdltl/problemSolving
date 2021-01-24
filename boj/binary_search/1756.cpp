#include <bits/stdc++.h>
using namespace std;
int oven[300001];

int main(){
    int ovenCnt, doughCnt;
    cin >> ovenCnt >> doughCnt;
    oven[0] = 0x7f7f7f7f;
    for( int i=1; i<=ovenCnt; i++ ){ 
        cin >> oven[i];
        oven[i] = min( oven[i], oven[i-1] );
    }

    int dough=0, pos=ovenCnt+1, old; 
    while( doughCnt-- ){
        old = dough;
        cin >> dough;
        if( !pos ) continue;
        if( dough <= old ){ pos--; continue; }
        int low=0, mid, high=pos-1;
        while( low<=high ){
            mid = (low+high)/2;
            if( dough <= oven[mid] ){ pos=mid; low=mid+1; }
            else high=mid-1;
        }
    }
    cout << pos <<'\n';
}