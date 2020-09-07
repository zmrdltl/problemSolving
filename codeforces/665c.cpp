#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    int t;
    cin >> t; 
    while(t--){
        int n;
        int cnt = 0;
        int flag = 0;
        int arr[100001];
        int minNum = 0x7f7f7f7f;
        vector <pair<int,int>> a;
        a.clear();
        memset(arr,0,sizeof(arr));
        cin >> n;

        for(int i = 0; i< n; i++) {
            cin >> arr[i]; 
            minNum = min(minNum,arr[i]);
        }

        for(int i = 0; i< n; i++) 
            if(arr[i]%minNum)
                a.push_back({arr[i],i});
        sort(a.begin(),a.end());
        sort(arr,arr+n);
        
        for(int i = 0; i<n; i++){
            if(arr[i]%minNum){
                if(arr[i] == a[cnt].first){
                    if(i!=a[cnt].second) {flag = 1;cout << "NO\n"; break;}
                    cnt++;
                }
            }
        }
        if(!flag) cout << "YES\n";
    }   
}