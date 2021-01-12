// #include <iostream>
// #include <cmath>
// using namespace std;

// int n,r,c,ans=0;

// void fillBoard(int n,int x,int y){
//     if(x== r && y == c){
//         cout << ans;
//         return;
//     }
//     if (y <= r && r < y + n && x <= c && c < x + n && ){
//         fillBoard(n/2,x,y);
//         fillBoard(n/2,x,y+n/2);
//         fillBoard(n/2,x+n/2,y);
//         fillBoard(n/2,x+n/2,y+n/2);
//     }
//     ans += n*n;
// }

// int main(){
//     cin >> n >> r >> c; // 2*n X 2*n의 판에서 (r,c)는 무슨 숫자?
//     fillBoard(1<<n,0,0);
// }

#include <iostream>

using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    Z(0, 0, (1 << n));
    return 0;
}