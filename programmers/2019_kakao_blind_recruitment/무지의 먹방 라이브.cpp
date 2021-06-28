#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> food_info; //<걸리는 시간, 순서>
	long long lastTime = 0; //바로 직전 검사한 음식의 걸리는 시간
	long long t = 0;
	int size = food_times.size();

	for (int i = 0; i < food_times.size(); i++)
		food_info.push_back(make_pair(food_times[i], i + 1));

	sort(food_info.begin(), food_info.end()); //소요 시간이 짧은 음식부터 검사 위함

	for (vector<pair<int, int>>::iterator i = food_info.begin(); i != food_info.end(); i++, size--) {
		t = (i -> first - lastTime) * size; 
		if (t <= k) {
			k -= t; //남은 시간 감소
			lastTime = i->first;
		}
		else {
			sort(i, food_info.end(), compare); //음식 번호순으로 다시 정렬
			return (i + (k % size)) -> second;
		}
	}
	return -1;
}