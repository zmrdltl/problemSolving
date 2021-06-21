#include <bits/stdc++.h>
using namespace std; 
bool visited[1001]; 
int main(void) { 
    int L, N; 
    cin >> L; 
    vector<int> S(L + 1, 0); 
    for (int i = 1; i <= L; i++) { 
        cin >> S[i]; 
        visited[S[i]] = true; 
    } 
    cin >> N; 
    if (visited[N]) { cout << 0 << "\n"; return 0; } 
    sort(S.begin(), S.end()); 
    int left = 0; 
    int right = 0; 
    for (int i = 0; i < L; i++) { 
        if (S[i] <= N && N < S[i + 1]) { 
            left = S[i]; right = S[i + 1]; 
            break; 
        } 
    } 
    cout << (N - left) * (right - N) - 1 << "\n"; 
}
