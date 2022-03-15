#include <bits/stdc++.h>
using namespace std;
int n, maxLength;
vector <int> nums;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int secondNum = i;
        int diff = n - secondNum;
        int length = 3;
        vector<int> v = {n, secondNum, diff};

        while(1){
            int tmp = diff;
            diff = secondNum - diff;
            if(diff < 0) break;
            secondNum = tmp;
            length++;
            v.push_back(diff);
        }

        if(maxLength < length) nums = v, maxLength = length;
    }
    cout << maxLength << '\n';
    for(auto e : nums) cout << e << ' ';
}