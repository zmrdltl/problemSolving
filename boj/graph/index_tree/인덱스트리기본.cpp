#include <bits/stdc++.h>
#define PIV (1<<4) // 1~16 N 10��
using namespace std;
int leafnode =   (1<<17); // N�� 10��
int tree[PIV*2];
void update(int n, int v)
{
    n += PIV;
    tree[n] = v;
    n/=2; // �ٷ��� �θ𿡼� ����
    while(n>0)
    {
        // ���� = �����ڽ� + �������ڽ�
        tree[n] = tree[n*2] + tree[n*2+1];
        n/=2; // �� �� �������� �ű�
    }
}
int query(int l, int r) // 2~7 ������ ������
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

//0,1,2... ��� ������ ������ �迭�� ������
/// 3��° ���� 6���� �ٲ�� 
int main()
{
    int ret = query(3,8); // 33
    update(2,6);
    ret = query(3,8); // 36
}