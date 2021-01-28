#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
using namespace std;

int binarySearch(int x,int n,vector <int> &num){
    int l = 0;
    int r = n-1;
    int flag = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(num[mid] >x){
            r = mid - 1;
        }else if(num[mid] < x){
            l = mid + 1;
        }else{
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    fastio;
    int t;
    cin >> t; 
    while(t--){
        int n,n2;
        cin >> n;
        vector <int> num(n);
        for(int i = 0; i < n; i++) cin >> num[i];
        sort(num.begin(),num.begin()+n);
        cin >> n2;
        for(int i = 0; i < n2; i++){
            int x;
            cin >> x;
            cout << binarySearch(x,n,num) <<'\n';
        }
    }
}