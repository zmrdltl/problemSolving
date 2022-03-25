#include <bits/stdc++.h>
using namespace std;
int a,b,m;
vector <int> nums;
stack <int> ans;

void converter(){
    int decimal = 0;
    int converted = 0;
    for(int i = 0; i < m; i++){
        decimal += nums[m - i - 1] * pow(a, i);
    }
    while(decimal){
        ans.push(decimal % b);
        decimal /= b;
    }
}

int main(){
    cin >> a >> b >> m;
    for(int i = 0, num; i < m; i++) {
        cin >> num;
        nums.push_back(num);
    }

    converter();

    while(ans.size()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}