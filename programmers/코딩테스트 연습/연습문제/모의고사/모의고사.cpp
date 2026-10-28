#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int an[5];

vector <int> solution(vector <int> answers) {
	vector<int> answer;
	int a[5] = { 1,2,3,4,5 };
	int b[8] = { 2,1,2,3,2,4,2,5 };
	int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int ans[3] = { 0,0,0 };

	for (int i = 0; i < answers.size(); i++)
	{
		if (a[i % 5] == answers[i])
		{
			ans[0]++;
		}
		if (b[i % 8] == answers[i])
		{
			ans[1]++;
		}
		if (c[i % 10] == answers[i])
		{
			ans[2]++;
		}
	}
	int big = 0;
	for (int i = 0; i < 3; i++)
	{
		big = max(ans[i], big);
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (big == ans[i])
		{
			answer.push_back(i + 1);
		}
	}
	return answer;
}
