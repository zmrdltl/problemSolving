#include <bits/stdc++.h>
using namespace std;

int n, meetDay;
vector<int> growDay;

int main(){
    cin >> n;
    growDay.resize(n);

    for(int i = 0; i < n; i++) cin >> growDay[i];

    sort(growDay.rbegin(), growDay.rend());

    for(int i = 0; i < growDay.size(); i++)
        meetDay = max(meetDay, growDay[i] + i + 1);

    cout << meetDay + 1;
}