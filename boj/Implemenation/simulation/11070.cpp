#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll expect[1001];
ll scoreGet[1001];
ll scoreLose[1001];
int n, m, t;
int a, b, p, q;
ll ans;
ll maxAns = -1;
ll minAns = 1001;	

int main() {
    cin >> t;
	while (t--) {
		ans = 0;
        maxAns = -1;
		minAns = 1001;
		memset(expect, 0, sizeof(expect));
		memset(scoreGet, 0, sizeof(scoreGet));
		memset(scoreLose, 0, sizeof(scoreLose));
        cin >> n >> m;
        while(m--){
            cin >> a >> b >> p >> q;
			scoreGet[a] += p;
			scoreLose[a] += q;
			scoreGet[b] += q;
			scoreLose[b] += p;
		}

		for (int i = 1; i <= n; i++) {
			if (!scoreGet[i]) ans = 0;
			else if ( !scoreLose[i]) ans = 1000;
			else
				ans = floor(1000 * (scoreGet[i] * scoreGet[i]) / (double)(scoreGet[i] * scoreGet[i] + scoreLose[i] * scoreLose[i]));
            maxAns = max(ans,maxAns);
            minAns = min(ans,minAns);
		}
		cout << maxAns << '\n' <<  minAns << '\n';
	}

}