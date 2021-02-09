#include <bits/stdc++.h>
using namespace std;
char s[500001];
stack <char> t, tmp;
int n, k, i;
int main() {
	cin >> n >> k >> s;
	int slen = strlen(s);
	for (i = 0; k;) {
		if (!t.empty() && (t.top() < s[i])) {
			t.pop();
			k -= 1;
		}
		else if (slen - i <= k) {
			i++;
			k -= 1;
		}
		else t.push(s[i++]);
	}
	while (!t.empty()) {
		tmp.push(t.top());
		t.pop();
	}
	while (!tmp.empty()) {
		cout << tmp.top();
		tmp.pop();
	}
	for (; s[i]; i++)
		cout << s[i];
}