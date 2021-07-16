#include <bits/stdc++.h>
#define PIV (1<<4) // 1~16 N 10만
using namespace std;
int leafnode =   (1<<17); // N이 10만
int tree[PIV*2];
void update(int n, int v)
{
    n += PIV;
    tree[n] = v;
    n/=2; // 바로위 부모에서 시작
    while(n>0)
    {
        // 조상 = 왼쪽자식 + 오른쪽자식
        tree[n] = tree[n*2] + tree[n*2+1];
        n/=2; // 그 윗 조상으로 옮김
    }
}
int query(int l, int r) // 2~7 까지의 구간합
{
    l += PIV, r += PIV;
    int ret = 0;
    while(l<=r)
    {
        if(l%2==1) ret += tree[l++];
        if(r%2==0) ret += tree[r--];
        l/=2, r/=2;
    }
    return ret; 
}

//0,1,2... 라는 순서를 가지는 배열이 있을때
/// 3번째 값을 6으로 바꿔라 
int main()
{
    int ret = query(3,8); // 33
    update(2,6);
    ret = query(3,8); // 36
}