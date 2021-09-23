#include <bits/stdc++.h>
using namespace std;
int n, inOrderIdx[100001], postOrder[100001],tree[100001][2];

//pl ~ pr postOrder�� ����, il ~ ir�� inOrder�� ����
int makeTree(int pl, int pr, int il, int ir){
    int root = postOrder[pr]; //postorder�� �������� �׻� ��Ʈ�̹Ƿ�
    int leftChildSize = inOrderIdx[root] - il; //inOrder�� ��Ʈ������ �����ڽ��̹Ƿ�
    if(pl == pr) return root;
    if(leftChildSize) tree[root][0] = makeTree(pl, pl + leftChildSize - 1, il, il + leftChildSize - 1);
    if(pl + leftChildSize <= pr - 1) tree[root][1] = makeTree(pl + leftChildSize, pr - 1, il + leftChildSize + 1, ir);
    return root;
}   

void preOrder(int x){
    if(!x) return;
    cout << x << ' ';
    preOrder(tree[x][0]);
    preOrder(tree[x][1]);
}

int main(){
    cin >> n;
    for(int i = 1,x; i <= n; i++) cin >> x, inOrderIdx[x] = i;
    for(int i = 1; i <= n; i++) cin >> postOrder[i];
    makeTree(1,n,1,n);
    preOrder(postOrder[n]);
    
}