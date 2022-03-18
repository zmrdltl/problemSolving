#include <bits/stdc++.h>
using namespace std;
int n, taeSuScore, p, score[51], rankcount, taeSuRank = 1;
int main() {
    cin >> n >> taeSuScore >> p;
	for (int i = 0; i < n; i++) cin >> score[i];

	for (int i = 0; i < n; i++) {
		if(taeSuScore < score[i]) taeSuRank++;
        if(taeSuScore > score[i]) break;
		rankcount++;
	}
	if (rankcount == p) taeSuRank = -1;
	if (n == 0) taeSuRank = 1;

	cout << taeSuRank;
}
