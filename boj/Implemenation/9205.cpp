//편의점을 들르면 맥주를 20개 풀로 채우기 가능
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        
        vector <pair<int,int>> v(101);
        vector <pair<int,int>> coordStore;
        vector <pair<int,int>> coordSangeunHome;
        vector <pair<int,int>> coordDestination;

        for(int i = 0; i < n + 2; i++){
            int x,y;

            cin >> x >> y;
            if(i==0) coordSangeunHome.push_back({x,y});
            else if(i==n+1) coordDestination.push_back({x,y});
            else coordStore.push_back({x,y});
        }
    }
}