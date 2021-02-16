#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a, string &b) { 
	return a + b > b + a;
}

string solution(vector<int> numbers) { 
	string answer = "";
	vector<string> s;
	for (auto n : numbers) s.push_back(to_string(n));
	sort(s.begin(), s.end(), cmp); 
	for (int i = 0; i < s.size(); i++) answer += s[i]; 
	if (answer[0] == '0') return "0"; 
	return answer;
}