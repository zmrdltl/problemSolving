//TODO 미완성
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    int r,b;
    cin >> r >> b;
    int total = r + b;
    for(int i = total/2; i>=1; i--){
        for(int j = total/2; j<=2005000; j++){
            if(i*j==total)
                cout << max(i,j) << ' ' << min(i,j) << '\n';
        }
    }
}