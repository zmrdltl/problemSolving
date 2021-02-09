#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack <int> s;
	int T, cnt = 0, pcnt=0,mcnt=0;
	cin >> T;
	int *a = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> a[i];
		if (a[i] > T)
			cout << "NO" << '\n'; return 0;
	}
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			if (a[i] > cnt)
			{
				s.push(++cnt);
				pcnt++;
			}
			if (s.top() == a[i])
			{
				s.pop();
				mcnt++;
				break;
			}

		}
	}
	if (pcnt != mcnt)
		cout << "NO"; return 0;
	cnt = 0;
	for (int i = 0; i < T; i++){
		for (int j = 0; j < T; j++)
		{
			if (a[i] > cnt)
			{
				s.push(++cnt);
				cout << "+" << '\n';
			}
			if (s.top() == a[i])
			{
				s.pop();
				cout << "-" << '\n';
				break;
			}
			
		}
	}
}