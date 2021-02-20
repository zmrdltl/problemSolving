#include <iostream>
#include <algorithm>
using namespace std;
int n,s,answer;
int tmp[21], ck[21], num[21];
int dfs(int depth,int index,int m) {
	int sum = 0;
	if (depth == m){
		for (int i = 0; i < m; i++) sum += tmp[i];
		return sum==s;
	}

    int ans = 0;
	for (int i = index; i < n; i++){
		if (!ck[i] ){
			ck[i] = 1;
			tmp [depth]= num[i];
			ans += dfs(depth + 1, i + 1,m);
			ck[i] = 0;
		}
	}
    
    return ans;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	for(int i = 0; i < n; i++) answer += dfs(0, 0, i + 1);
	cout << answer << '\n';
}