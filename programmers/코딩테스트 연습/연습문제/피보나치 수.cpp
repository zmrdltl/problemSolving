#include <bits/stdc++.h>
using namespace std;
int solution(int n) {
    int answer = 0;
    int a[100001];
    memset(a,0,sizeof(a));
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i <= n; i++)
        a[i] = (a[i-1] + a[i-2]) % 1234567;
    return a[n];
}