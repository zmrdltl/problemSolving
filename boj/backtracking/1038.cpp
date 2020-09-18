#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll n, answer, decresingNumber[1024];

void dfs(ll num){
    ll units = num % 10, next = num * 10;
    for(int i = 0; i < units; i++){
        decresingNumber[answer++] = next + i;
        dfs(next + i);
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < 10; i++){
        decresingNumber[answer++] = i;
        dfs(i);
    }

    sort(decresingNumber, decresingNumber + answer);
    if(n < answer) cout <<  decresingNumber[n];
    else cout << -1 <<'\n';
}