#include <bits/stdc++.h>
using namespace std;

struct Node { int key; Node *left,*right; };
int n;

Node *addNode(Node *node, int key){
    if(node == NULL){
        node = new Node();
        node -> key = key;
        node->left = node->right = NULL;
    }
    else if(key < node->key) node->left = addNode(node->left,key);
    else node->right = addNode(node->right,key);
    return node;
}

void postOrder(Node *node){
    if(node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << '\n';
}

int main(){
    Node *tree = NULL;
    while(cin >> n) tree = addNode(tree,n);
    postOrder(tree);
}