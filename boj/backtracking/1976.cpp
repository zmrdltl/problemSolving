#include <bits/stdc++.h>
using namespace std;
int n,m,graph[201][201];
vector<int>course;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1,x; j <= n; j++){
            cin >> graph[i][j];
        }
        graph[i][i] = 1;
    }

    while(m--){
        int x;
        cin >> x;
        course.push_back(x);
    }
    
    sort(course.begin(),course.end());

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][k] && graph[k][j]){
                    graph[i][j] = 1;
                }
            }
        }
    }
    int flag = 0;
    for(int i = 0; i < course.size() - 1; i++){
        if(!graph[course[i]][course[i+1]] && !graph[course[i+1]][course[i]]) flag = 1;
    }
    if(flag) cout << "NO";
    else cout << "YES";
}