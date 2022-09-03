#include <bits/stdc++.h>
using namespace std;
struct Info{ int score, commit, loaded, num; };
int n;
vector <Info> v;

bool cmp(Info a, Info b){
  if(a.score == b.score) {
    if(a.commit == b.commit) return a.loaded < b.loaded;
    return a.commit < b.commit;
  }
  return a.score > b.score;
}

int main(){
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].score >> v[i].commit >> v[i].loaded;
    v[i].num = i+1;
  }
  sort(v.begin(), v.end(), cmp);
  cout << v[0].num;
}