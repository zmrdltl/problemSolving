#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define MAX 10000000000000;
using namespace std;

ll solution(int n, vector<int> times) {
    ll answer = MAX;
    ll timeSize = times.size();
    ll l = 1, r = MAX;
    while(l<=r){
        ll mid = (l + r)/2;
        ll sum = 0;
        for(int i = 0 ; i < timeSize; i++) sum += mid/times[i];
        if(sum>=n){r = mid - 1; answer = min(answer,mid);}
        else if(sum<n){l = mid+1;}
    }
    return answer;
}
int main(){
    vector <int> times({1000000000,1000000000,1000000000});
    int n = 100000;
    cout <<solution(n,{1000000000,1000000000,1000000000});
}