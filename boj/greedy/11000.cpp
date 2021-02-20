#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>; 
int n;
vector<pii> lecture(n);
priority_queue<int, vector<int>, greater<int>> pq;
 
int main(){
    cin >> n;
    lecture.resize(n);

    for(int i = 0; i < n; i++)
        cin >> lecture[i].first >> lecture[i].second;
    sort(lecture.begin(), lecture.end());
    pq.push(lecture[0].second);
    
    for(int i = 1; i < n; i++){
        if(pq.top() <= lecture[i].first){
            pq.pop();
            pq.push(lecture[i].second);
        }else pq.push(lecture[i].second);
    }

    cout << pq.size() << '\n';
}

