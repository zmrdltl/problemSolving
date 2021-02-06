#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<int> vec(101);
vector<int> visited(101);
vector<int> ans;
void dfs(int startNode,int currentNode){
    if(visited[currentNode]){
        if(currentNode==startNode)
            ans.push_back(startNode);
    }else{
        visited[currentNode]++;
        dfs(startNode,vec[currentNode]);
    }
    
}
int main(){
    
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin >> vec[i];
    }
    
    for(int i=1;i<=n;i++){
        dfs(i,i);
        visited=vector<int> (n+1,0);
    }
    
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
}