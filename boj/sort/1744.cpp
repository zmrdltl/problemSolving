#include <bits/stdc++.h>
using namespace std;
vector <int> minusNum;
vector <int> plusNum;
int n, ans;
int main(){
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if(x > 0) plusNum.push_back(x);
        else minusNum.push_back(x);
    }
    sort(plusNum.begin(),plusNum.end());
    sort(minusNum.begin(),minusNum.end());

    for(int i = plusNum.size() - 1; i >= 0; i-=2){
        int mul = 1;
        int sum = 0;
        mul *= plusNum[i];
        sum += plusNum[i];
        if(i-1>=0) mul *= plusNum[i-1], sum += plusNum[i-1];
        ans += max(mul,sum);
    }
    
    for(int i = 0; i < minusNum.size(); i+=2){
        int mul = 1;
        int sum = 0;
        mul *= minusNum[i];
        sum += minusNum[i];
        if(i+1<minusNum.size()) mul *= minusNum[i+1], sum += minusNum[i+1];
        ans += max(mul,sum);
    }
    cout << ans << '\n';
}