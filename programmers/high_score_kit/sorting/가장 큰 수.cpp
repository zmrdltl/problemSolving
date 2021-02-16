#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    if(sa[0]==sb[0]) {
        return sa > sb;
    }
    
    return sa[0] > sb[0];
}
string solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end(),cmp);
    string ans = "";
    for(auto n : numbers) ans += to_string(n);
    return ans;
}