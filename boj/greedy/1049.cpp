#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;
int n,m,case1,case2,case3;
int packageMin = INF, eachMin = INF;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int six,one;
        cin >> six >> one;
        packageMin = min(six,packageMin);
        eachMin = min(one, eachMin);
    }
    //n개 이상으로 줄을 패키지 살 때
    if(n % 6 == 0) case1 = n / 6 * packageMin;
    else case1 = (n / 6 + 1) * packageMin;
    
    //2. n개 이상 줄을 1개씩 살 때
    case2 = eachMin * n;

    //3. n개 미만으로 최대한 6개씩 산 후 나머지를 1개씩 살 때
    case3 = n / 6 * packageMin + n % 6 * eachMin;
    cout << min({case1,case2,case3});
}