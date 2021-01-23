#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll b, n;
	cin >> b >> n;

	ll tmp = n;
	ll sum = 1; 
	ll jisu = 1;
	while (tmp--) {
		sum += 1 << jisu;
		jisu += 1; 
	}

	if (1 << b <= sum) 
		cout << "yes" << endl;
	else 
		cout << "no" << endl;
}