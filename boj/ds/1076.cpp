#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ret;
ll ans;
map<string,ll> m;
int main() {
	string color;
	for (int i = 1; i <= 3; i++)
	{
		cin >> color;
		if (i != 3)
		{
			if (color == "black" )
				ret += "0";
			else if (color == "brown" )
				ret += "1";
			else if (color == "red" )
				ret += "2";
			else if (color == "orange" )
				ret += "3";
			else if (color == "yellow" )
				ret += "4";
			else if (color == "green" )
				ret += "5";
			else if (color == "blue" )
				ret += "6";
			else if (color == "violet")
				ret += "7";
			else if (color == "grey")
				ret += "8";
			else
				ret += "9";
		}
		else//i가 마지막일 경우
		{
			long long s = stoll(ret);
			if (color == "black")
				ans = s;
			else if (color == "brown")
				ans = s * 10;
			else if (color == "red")
				ans = s * 100;
			else if (color == "orange")
				ans = s * 1000;
			else if (color == "yellow")
				ans = s * 10000;
			else if (color == "green")
				ans = s * 100000;
			else if (color == "blue")
				ans = s * 1000000;
			else if (color == "violet")
				ans = s * 10000000;
			else if (color == "grey")
				ans = s * 100000000;
			else
				ans = s * 1000000000;
		}
	}
	cout << ans << '\n';
}