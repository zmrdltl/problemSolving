#include <bits/stdc++.h>
using namespace std;
int key;

struct Node{
    int key;
    Node *left;
    Node *right;
};

Node *addNode(Node *node, int key){
    if(node == NULL) {
        node = new Node();
        node->key = key;
        node->left = node->right = NULL;
    }
    else if(key <= node->key) node->left = addNode(node->left,key);
    else node->right = addNode(node->right,key);
    return node;
}

void postOrder(Node* node){
    if(node->left != NULL) postOrder(node->left);
    if(node->right != NULL) postOrder(node->right);
    cout << node->key << '\n';
}

int main(){
    Node *tree = NULL;
    while(cin>>key){
        tree = addNode(tree,key);
    }
    postOrder(tree);
}