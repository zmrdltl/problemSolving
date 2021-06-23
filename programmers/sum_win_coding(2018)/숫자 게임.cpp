#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    vector <int> ans;
    sort(B.rbegin(), B.rend());
    sort(A.rbegin(), A.rend());
    int aIdx = 0, bIdx = 0;
    if(A[A.size() - 1] >= B[0]) return 0;
    for(int i = 0; i < A.size(); i++){
        if(A[aIdx] < B[bIdx]) answer++, bIdx++;
        aIdx++;
    }
    return answer;
}