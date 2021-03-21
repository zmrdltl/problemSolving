#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int parent[100001];

int find(int a){
    if(a == parent[a]) return a;
    return a = find(parent[a]);
}

int unionParent(int a,int b){
    if(a < b ) parent[b] = a;
    else parent[a] = b;
}

bool cmp(vector<int> &a, vector<int>&b){
    return a[2] < b[2];    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //vector <int > parent(n);
    //int parent[101];
    
    
    
    for(int i = 0; i <= 100000; i++) parent[i] = i;
    
    //간선 정렬
    //find 다르면 union
    sort(costs.begin(),costs.end(),cmp);
    int cnt = 0;
    for(int i = 0; i < costs.size(); i++){
        int a = find(costs[i][0]);
        int b = find(costs[i][1]);
        cout << a << ' ' << b << '\n';
        cout << parent[a] << ' ' << parent[b] << '\n';
        if(cnt==n-1) break;
        if(a != b){
            //unionParent(a,b);
            cnt++;
            answer += costs[i][2];
        }
        cout << answer << ' ' << cnt <<'\n';
    }
    
    
    return answer;
}

int main(){

    vector<vector<int>> costs;
    vector <int> tmp = {0,1,1};
    costs.push_back((tmp));
    vector <int> tmp1 = {0,2,2};
        costs.push_back((tmp1));
    vector <int> tmp2 = {1,2,5};
        costs.push_back((tmp2));
    vector <int> tmp3 = {1,3,1};
        costs.push_back((tmp3));
    vector <int> tmp4 = {2,3,8};
        costs.push_back((tmp4));
    cout << solution(4,costs);
    cout << solution(4,costs);
}