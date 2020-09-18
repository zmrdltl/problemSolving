#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector <int> fireXPosition(100001);
vector <pair<int,int>> animalPosition;
int fireNum, animalNum, fireRange, ans = 0;
 
int main() {
    int M, N, L, x, y, cnt=0;
    vector<int> m;
    scanf("%d %d %d", &M, &N, &L);
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        m.push_back(tmp);
    }
    sort(m.begin(), m.end());
    for (int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        if (y > L) continue;
        int upper = x+L-y, lower = x+y-L, low = 0, high = m.size()-1; // x+=r에 사로가 있으면 됨
        while (low<=high) {
            int mid = (low + high) / 2;
            if (lower <= m[mid] && m[mid] <= upper) {
                cnt++;
                break;
            }
            else if (m[mid] < lower) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    printf("%d\n", cnt);
}
