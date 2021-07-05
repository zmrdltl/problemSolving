#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n,m,x;
int a[100001];

int binarySearch(int x){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] < x) left = mid + 1;
        else if(a[mid] > x) right = mid - 1;
        else return 1;
    }
    return 0;
}
int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        cout << binarySearch(x) << '\n';
    }
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// using namespace std;
// int n,m;
// vector <int> a;

// int main(){
//     fastio;
//     cin >> n;
//     for(int i = 0,x; i < n; i++) { cin >> x, a.push_back(x); }
//     sort(a.begin(), a.end());
//     cin >> m;
//     for(int i = 0; i < m; i++){
//         int x;
//         cin >> x;
//         cout << binary_search(a.begin(),a.end(),x) << '\n';
//     }
// }
