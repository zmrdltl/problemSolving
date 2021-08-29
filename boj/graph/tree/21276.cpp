#include <bits/stdc++.h>
using namespace std;
int n, m, ind[1001], familyNum;
vector <int> graph[1001], childName[1001];
map <string,int> familyIdxMap;
map <int,string> familyNameMap;
vector <string> ancestor;

void topologySort(string anc){
    queue <int> q;
    q.push(familyIdxMap[anc]);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : graph[x]){
            ind[next]--;
            if(ind[next]) continue;
            childName[x].push_back(next);
            q.push(next);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        familyIdxMap[s] = i;
        familyNameMap[i] = s;
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        string a,b;
        cin >> a >> b;
        ind[familyIdxMap[a]]++;
        graph[familyIdxMap[b]].push_back(familyIdxMap[a]);
    }
    
    for(int i = 0; i < n; i++)
        if(!ind[i]) 
            ancestor.push_back(familyNameMap[i]);

    sort(ancestor.begin(),ancestor.end());

    for(auto a : ancestor) topologySort(a);

    cout << ancestor.size() << '\n';
    for(auto a : ancestor) cout << a << ' ';
    cout << '\n';

    for(auto f : familyIdxMap){
        cout << f.first << ' ' << childName[f.second].size() << ' ';
        vector <string> v;
        for(auto next : childName[f.second]) v.push_back(familyNameMap[next]);
        sort(v.begin(),v.end());
        for(auto el : v) cout << el << ' ';
        cout << '\n';
    }
}