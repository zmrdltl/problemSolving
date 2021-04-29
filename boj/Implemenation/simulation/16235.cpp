#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dx[] = { -1,-1,-1,0,0,1,1,1 }; 
int dy[] = { -1,0,1,-1,1,-1,0,1 }; 
int addNutrients[11][11], nutrients[11][11];
vector<int> land[11][11]; 

int aliveTree = 0;

void springSummer(){
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
            
            if(!land[r][c].size()) continue;
			sort(land[r][c].begin(), land[r][c].end());
			int die = 0;
			int addNut = 0;
			for (int age = 0; age < land[r][c].size(); age++) {
				if (land[r][c][age] <= nutrients[r][c]) {
					nutrients[r][c] -= land[r][c][age];
					land[r][c][age]++;
				}

				else {
					aliveTree--;
					die++;
					addNut += land[r][c][age] / 2;
				}
			}
            nutrients[r][c] += addNut;
			while(die--) land[r][c].pop_back();
		}
	}
}

void fallWinter(){
	for(int r = 1; r <= n; r++){
		for (int c = 1; c <= n; c++) {
    		nutrients[r][c] += addNutrients[r][c];
			if(!land[r][c].size()) continue;
			for (int age = 0; age < land[r][c].size(); age++) {
                if(land[r][c][age] <= 0 || land[r][c][age] % 5) continue;
                for (int d = 0; d < 8; d++) {
					int nx = r + dx[d];
					int ny = c + dy[d];
					if (1 > nx || nx > n || 1 > ny || ny > n) continue;
					land[nx][ny].push_back(1);
					aliveTree++;
				}
			}

		}
	}
}


int main(){
    cin >> n >> m >> k;
	aliveTree = m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            cin >> addNutrients[i][j];
			nutrients[i][j] = 5;
		}
	}

    while(m--){
		int x, y, age;
        cin >> x >> y >> age;
		land[x][y].push_back(age);
	}

    while(k--){
		springSummer();
    	fallWinter();
	}

    cout << aliveTree;
}