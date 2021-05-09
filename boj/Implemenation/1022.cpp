#include <iostream>
using namespace std;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int board[50][5], curX, curY, dir = 3;
int cnt, num = 1, dcnt = 1;

int main(){
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	while (!board[r2 - r1][0] || !board[0][0] || !board[0][c2 - c1] || !board[r2 - r1][c2 - c1]) {

		if (curY - r1 >= 0 
        && curY - r1 <= (r2 - r1) 
        && curX - c1 >= 0 
        && curX - c1 <= (c2 - c1)) {
			board[curY - r1][curX - c1] = num;
		}

		cnt++;
		num++;

		curX = curX + dx[dir];
		curY = curY + dy[dir];

		if (cnt == dcnt) {
			cnt = 0;
			dir = (dir + 1) % 4;
			if (dir == 1 || dir == 3)
				dcnt += 1;
		}
	}


	cnt = 0;

	while (num) {
		num /= 10;
		cnt += 1;
	}

	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++) {
			printf("%*d ", cnt, board[i][j]);
		}
		cout << "\n";
	}
}