#include <iostream>
#include <vector>
using namespace std;
 
int n, m, k;
int parents[51];

vector<int> know;
vector<vector<int> > v(50);
 
 
int Find(int x) {
    if (parents[x] == x) return x;
    return x = Find(parents[x]);
}
 
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}
 
 
 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
 
    while (k--) {
        int t;
        cin >> t;
        know.push_back(t);
    }
 
    for (int i = 1; i <= n; i++) parents[i] = i;
 
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int num;
        int prev;
        for (int j = 0; j < p; j++) {
            if (j >= 1) {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else {
                cin >> num;
            }
            v[i].push_back(num);
        }
    }
    for (auto& list : v) {
        bool flag = false;
        for (auto& person : list) {
            if (flag) break;
            for (auto& t : know) {
                if (Find(person) == Find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)m--;
    }
    cout << m;
}
