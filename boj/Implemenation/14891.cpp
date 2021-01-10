#include <bits/stdc++.h>
using namespace std;

int direction[4];
vector<vector<int>> gear;

vector <int> getGearVector(string gearInfo){
    vector <int> tmpGear;
    for(int i = 0; i < 8; i++)
        tmpGear.push_back(gearInfo[i] - '0');
    return tmpGear;
}

void fillDirection(int start, int rotateDirection) {
	int next = start + 1;
	int prev = start - 1;
	direction[start] = rotateDirection;
	if (next < 4 && direction[next] == 0 && gear[start][2] != gear[next][6]) {
		fillDirection(next, rotateDirection * -1);
	}
	if (prev >= 0 && direction[prev] == 0 && gear[start][6] != gear[prev][2]) {
		fillDirection(prev, rotateDirection * -1);
	}
}

void rotateGear() {
	for (int i = 0; i < 4; i++) {
		if (direction[i] == 1) {//시계방향
			int temp = gear[i][7];
			for (int j = 7; j > 0; j--)
				gear[i][j] = gear[i][j - 1];
			gear[i][0] = temp;
		}
		else if (direction[i] == -1) {//반시계방향
			int temp = gear[i][0];
			for (int j = 0; j <7; j++)
				gear[i][j] = gear[i][j + 1];
			gear[i][7] = temp;
		}
	}
}

void clearDirection() {
	for (int i = 0; i < 4; i++) {
		direction[i] = 0;
	}
}

int getPoint(){
    int point = 0;
    for(int i =0; i < 4; i++){
        if(gear[i][0]) point += pow(2,i);
    }
    return point;
}

int main() {
	int gearNum;
	int rotateDirection;
	int k;

	for (int i = 0; i < 4; i++) {
    	string gearInfo;
		cin >> gearInfo;
		gear.push_back(getGearVector(gearInfo));
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> gearNum >> rotateDirection;
		fillDirection(gearNum-1, rotateDirection);
		rotateGear();
		clearDirection();
	}

	cout << getPoint();
}
