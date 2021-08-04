#include <bits/stdc++.h>
using namespace std;
struct Coords {int r,c;};
char board[6][6];
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};
int n, canSee[6][6] ;
bool isSafe;
vector <Coords> emptySpace, teachers, students;


void checkArea(){
    for(auto t : teachers){
        for(int dir = 0; dir < 4; dir++){
            int nr = t.r;
            int nc = t.c;
            canSee[nr][nc] = 1;
            while(1){
                nr += dr[dir];
                nc += dc[dir];
                if(0 > nr || nr >= n || 0 > nc || nc >= n) break;
                if(board[nr][nc] == 'O') break;
                canSee[nr][nc] = 1;
            }
        }
    }
}

void dfs(int depth, int idx) {
	if (depth == 3) {
        memset(canSee,0,sizeof(canSee));
        
        checkArea();

        for(auto s : students)
            if(canSee[s.r][s.c]) return;

        isSafe = true;
        return;
	}

    for(int i = idx; i < emptySpace.size(); i++){
        int r = emptySpace[i].r;
        int c = emptySpace[i].c;
        board[r][c] = 'O';
        dfs(depth+1, i + 1);
        board[r][c] = 'X';
    }
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T') teachers.push_back({ i,j });
			if (board[i][j] == 'X') emptySpace.push_back({ i,j });
            if (board[i][j] == 'S') students.push_back({ i,j });
		}
	}

	dfs(0, 0);
    if(isSafe) cout << "YES";
    else cout << "NO";
}