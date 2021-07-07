#include <bits/stdc++.h>
using namespace std;
int n, a[26][2];

void preOrder(int x){
    if(x == -1) return;
    printf("%c",x + 'A');
    preOrder(a[x][0]);
    preOrder(a[x][1]);
}

void inOrder(int x){
    if(x == -1) return;
    inOrder(a[x][0]);
    printf("%c",x + 'A');
    inOrder(a[x][1]);
}

void postOrder(int x){
    if(x == -1) return;
    postOrder(a[x][0]);
    postOrder(a[x][1]);
    printf("%c",x + 'A');
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        if(leftChild == '.') a[parent - 'A'][0] = -1;
        else a[parent - 'A'][0] = leftChild - 'A';

        if(rightChild == '.') a[parent - 'A'][1] = -1;
        else a[parent - 'A'][1] = rightChild - 'A';
        
    }

    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
}