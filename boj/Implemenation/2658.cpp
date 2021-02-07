#include <bits/stdc++.h>
using namespace std;
int board[10][10];
pair<int,int> ans[3];
void rotateTriangle(){
    int tmp[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            tmp[i][j] = board[i][j];
    
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            board[i][j] = tmp[9-j][i];
}

void rotatePoint(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int x = ans[j].second;
            int y = ans[j].first;
            ans[j].first = 9 - x;
            ans[j].second = y;
        }
    }
}

void printAns(pair<int,int> ans[3]){
    for(int i = 0; i < 3; i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 <<'\n';
}

bool check() {
	int tmp[10][10];
	memset(tmp, 0, sizeof(tmp));

    int x = -1;
	int y = -1;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (board[i][j]) { y = i; x = j; break;}
		if (y != -1) break;
	}
	if (y == -1) return false;
	ans[0] = { y, x };

	for (int i = 0; i + y < 10; i++) {
		if (board[i + y][x] == 1) {
			if (x - i < 0 || x + i >= 10) return false;
			ans[1] = { y + i, x - i };
			ans[2] = { y + i, x + i };
			for (int j = x - i; j <= x + i; j++)
				tmp[i + y][j] = 1;
		}
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (tmp[i][j] != board[i][j])
				return false;

	return true;
}

bool check1() {
    int x = -1;
	int y = -1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (board[i][j] == 1) { y = i, x = j; break; }
		if (y != -1) break;
	}
	if (y == -1) return false;

	ans[0] = { y, x };

	int tmp[10][10];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i + y < 10; i++) {
		if (board[i + y][x] == 1) {
			if (x + i >= 10) return false;
			ans[1] = { y + i, x };
			ans[2] = { y + i, x + i };
			for (int j = x; j <= x + i; j++) {
				tmp[i + y][j] = 1;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (tmp[i][j] != board[i][j])
				return false;

	return true;
}

int main(){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            scanf("%1d",&board[i][j]);

    for (int i = 0; i < 4; i++) {
		rotateTriangle();
		if (check()) {
			rotatePoint(i + 1);
			sort(ans, ans + 3);
			printAns(ans);
            return 0;
		}
		if (check1()) {
			rotatePoint(i + 1);
			sort(ans, ans + 3);
			printAns(ans);
            return 0;
		}
	}
    cout << 0 << '\n';
}