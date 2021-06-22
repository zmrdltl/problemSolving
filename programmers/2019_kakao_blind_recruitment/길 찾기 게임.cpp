#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

struct Tree {
    int index;
    Tree *left;
    Tree *right;
};

Tree *makeTree(vvi &nodeinfo , int start, int end) {
    if(start > end) return NULL;
    int maxHeight = nodeinfo[start][1];
    int curNodeIdx = start;
    for(int i = start + 1; i <= end; i++){
        if(maxHeight < nodeinfo[i][1]){
            maxHeight = nodeinfo[i][1];
            curNodeIdx = i;
        }
    }

    Tree *node = new Tree();
    node->index = nodeinfo[curNodeIdx][2];
    node->left = makeTree(nodeinfo,start,curNodeIdx-1);
    node->right = makeTree(nodeinfo,curNodeIdx + 1, end);
    return node;
}

void preOrder(Tree *tree, vi &result){
    if(tree == NULL) return;
    result.push_back(tree->index);
    preOrder(tree->left, result);
    preOrder(tree->right, result);
}

void postOrder(Tree *tree, vi &result){
    if(tree == NULL) return;
    postOrder(tree->left, result);
    postOrder(tree->right, result);
    result.push_back(tree->index);
}

vvi solution(vvi nodeinfo) {
    vvi answer;
    vi pre,post;
    for(int i = 0; i < nodeinfo.size(); i++) nodeinfo[i].push_back(i+1);
    sort(nodeinfo.begin(),nodeinfo.end());
    Tree *tree = makeTree(nodeinfo,0,nodeinfo.size()-1);
    preOrder(tree, pre);
    postOrder(tree, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}