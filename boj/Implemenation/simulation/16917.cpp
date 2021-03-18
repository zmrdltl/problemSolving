#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,y,ans;
int arr[2];
int main(){
    //a : 양념, b : 후리이드, c : 반반
    cin >> a >> b >> c >> x >> y;
    int c1 = a * x + b * y; //따로
    int c2 = max(x,y)*2*c; //반반만
    int c3 = min(x,y) *2 * c; //반반먼저산 뒤 따로
    int m = min(x,y);
    x-=m;
    y-=m;
    c3 += a * x + b * y;
    cout << min({c1,c2,c3}) <<'\n';
}