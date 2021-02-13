#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int paperNum;
vector<pii> paperInfo;
int cache[102];

bool check(pii a, pii b) { //a위에 b를 올릴 수 있는가?
	if (a.first >= b.first && a.second >= b.second) return true;
	if (a.first >= b.second && a.second >= b.first) return true;
	return false;
}

bool cmp(const pii& a, const pii& b) {
	return a.first*a.second > b.first*b.second;
}

int dp(int pos){
    if (pos == paperNum+1) return 0;
	int& ret = cache[pos];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = pos + 1; i <= paperNum+1; i++) 
		if (i == paperNum+1 || check(paperInfo[pos], paperInfo[i]))
			ret = max(ret, dp(i) + 1);
    return ret;
}

int main() {
	cin >> paperNum;
	paperInfo.resize(paperNum+1);
	paperInfo[0] = { 1000, 1000 };
	for (int i = 1; i <= paperNum; i++)
		cin >> paperInfo[i].first >> paperInfo[i].second;
	sort(paperInfo.begin(), paperInfo.end(), cmp);
	memset(cache, -1, sizeof(cache));
    
	cout << dp(0) - 1;
}