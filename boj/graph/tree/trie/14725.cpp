#include <bits/stdc++.h>
using namespace std;
int t;

struct Node{
    map <string, Node> child;
}root;

void insert(Node &root, vector<string>arr, int idx){
    if(idx == arr.size()) return;
    if(!root.child.count(arr[idx])) root.child[arr[idx]] = Node();
    insert(root.child[arr[idx]], arr, idx + 1);
}

void dfs(Node &root, int depth){
    for(auto el : root.child){
        for(int i = 0; i < depth; i++) cout << "--";
        cout << el.first << '\n';
        dfs(el.second, depth + 1);
    }

}

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <string> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        insert(root, arr, 0);
    }
    dfs(root,0);
}