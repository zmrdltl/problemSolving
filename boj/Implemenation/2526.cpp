#include <bits/stdc++.h>
using namespace std;
int n,p,ne,cnt=1;
vector <int> nums(1001); 

int main(){
    cin >> n >> p;
    ne = n;
    while(!nums[ne]){
        nums[ne] = cnt++;
        ne = ne * n % p;
    }
    cout << cnt - nums[ne] << '\n';
}