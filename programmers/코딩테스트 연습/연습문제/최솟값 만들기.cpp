#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int size = A.size();
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    for(int i = 0; i < size; i++) answer += A[i] * B[i];
    return answer;
}