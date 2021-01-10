#include <bits/stdc++.h>
using namespace std;

int direct[4];
vector<vector<int>> cgear;
void fillDirect(int start, int direction) {
	int next = start + 1;
	int prev = start - 1;
	direct[start] = direction;
	if (next < 4 && direct[next] == 0 && cgear[start][2] != cgear[next][6]) {
		fillDirect(next, direction * -1);
	}
	if (prev >= 0 && direct[prev] == 0 && cgear[start][6] != cgear[prev][2]) {
		fillDirect(prev, direction * -1);
	}
}

void rotation() {
	for (int i = 0; i < 4; i++) {
		if (direct[i] == 1) {//시계방향
			int temp = cgear[i][7];
			for (int j = 7; j > 0; j--) {
				cgear[i][j] = cgear[i][j - 1];
			}
			cgear[i][0] = temp;
		}
		else if (direct[i] == -1) {//반시계방향
			int temp = cgear[i][0];
			for (int j = 0; j <7; j++) {
				cgear[i][j] = cgear[i][j + 1];
			}
			cgear[i][7] = temp;
		}
	}
}

void directClear() {
	for (int i = 0; i < 4; i++) {
		direct[i] = 0;
	}
}

int solution(vector<vector<int>> gear, int K, vector<vector<int>>rotate) {
	cgear = gear;
	for (int i = 0; i < K; i++) {
		int rotateIndex = rotate[i][0] - 1;
		int direction = rotate[i][1];
		fillDirect(rotateIndex, direction);
		rotation();
		directClear();
	}
	
	int score = 0;
	for (int j = 0; j < 4; j++) {
		if (cgear[j][0] == 1) {
			score += (int)pow(2, j);
		}
	}
	return score;

}

int main() {
	string gear;
	vector<int> gearInside;
	vector<vector<int>>gearOutside;
	for (int i = 0; i < 4; i++) {
		cin >> gear;
		for (int j = 0; j < 8; j++) {
			gearInside.push_back(gear[j]-'0');
		}
		gearOutside.push_back(gearInside);
		gearInside.clear();
	}
	int K;
	cin >> K;
	vector<int> rotateIn;
	vector<vector<int>>rotateOut;
	int gearNum;
	int direct;
	for (int i = 0; i < K; i++) {
			cin >> gearNum;
			rotateIn.push_back(gearNum);
			cin >> direct;
			rotateIn.push_back(direct);
			rotateOut.push_back(rotateIn);
			rotateIn.clear();
	}
	int ans = solution(gearOutside, K, rotateOut);
	cout << ans;
}
