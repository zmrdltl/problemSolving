#include <iostream> 
#include <algorithm> 
#include <math.h> 
using namespace std;
int N, M; 
char map[10][10]; 
int ans; bool b_hole; // true if blue goes down to hole 
//©Л го аб ╩С

int dR[4] = {0, 1, 0, -1}; 
int dC[4] = {1, 0, -1, 0}; 
void copy_map(char temp[10][10], char ori[10][10]) {
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) { 
            temp[i][j] = ori[i][j]; 
        } 
    }
} // initial cnt == 1 
void dfs(int r_r, int r_c, int b_r, int b_c, int cnt) { 
    if (cnt >= ans) return;
    char restore[10][10]; 
    copy_map(restore, map); 
    int n_r_r; int n_r_c; int n_b_r; int n_b_c; 
    char red_ori; char blue_ori; 
    bool red_hole; bool blue_hole; 
    bool red_stuck; 
    for (int dir = 0; dir < 4; dir++) { 
        n_r_r = r_r + dR[dir]; 
        n_r_c = r_c + dC[dir]; 
        n_b_r = b_r + dR[dir]; 
        n_b_c = b_c + dC[dir]; 
        // check if balls went to the hole 
        red_hole = false; blue_hole = false; 
        // if red is stuck with blue first 
        red_stuck = false; 
        // check whether it moved or not 
        // move Red 
        while (map[n_r_r][n_r_c] == '.') { 
            n_r_r += dR[dir]; 
            n_r_c += dC[dir]; 
        } 
        if (map[n_r_r][n_r_c] == '#') { 
            swap(map[n_r_r - dR[dir]][n_r_c - dC[dir]], map[r_r][r_c]); 
        } 
        else if (map[n_r_r][n_r_c] == 'B') { red_stuck = true; } // hole 
        else { map[r_r][r_c] = '.'; red_hole = true; } // move Blue 
        while (map[n_b_r][n_b_c] == '.') { 
            n_b_r += dR[dir]; n_b_c += dC[dir]; 
        } 
        if ((map[n_b_r][n_b_c] == '#') || (map[n_b_r][n_b_c] == 'R')) {
            swap(map[n_b_r - dR[dir]][n_b_c - dC[dir]], map[b_r][b_c]); 
        } // hole 
        else { map[b_r][b_c] = '.'; blue_hole = true; } 
        if (red_stuck) { // move Red 
            while (map[n_r_r][n_r_c] == '.') { 
                n_r_r += dR[dir]; 
                n_r_c += dC[dir]; 
            } 
            if ((map[n_r_r][n_r_c] == '#') || (map[n_r_r][n_r_c] == 'B')) {
                swap(map[n_r_r - dR[dir]][n_r_c - dC[dir]], map[r_r][r_c]); 
            } // hole 
            else { map[r_r][r_c] = '.'; red_hole = true; } } // If blue goes down or get stuck, pass 
            if (blue_hole) { copy_map(map, restore); continue; } 
            else if (red_hole) { 
                if (blue_hole) { copy_map(map, restore); } 
                else { 
                    copy_map(map, restore); 
                    ans = min(ans, cnt); return; 
                } 
            } 
            else if ((r_r == n_r_r - dR[dir] && r_c == n_r_c - dC[dir] && b_r == n_b_r - dR[dir] && b_c == n_b_c - dC[dir])) { continue; } // red and blue is not in the hole 
            else { 
                dfs(n_r_r - dR[dir], n_r_c - dC[dir], n_b_r - dR[dir], n_b_c - dC[dir], cnt + 1); // restore map 
                copy_map(map, restore); 
                } 
    } 
} 
int main() { 
    ans = 11; 
    b_hole = false; 
    cin >> N >> M; 
    int r_r = 0, r_c = 0, b_r = 0, b_c = 0; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            cin >> map[i][j]; 
            if (map[i][j] == 'R') { 
                r_r = i; r_c = j; 
            } 
            else if (map[i][j] == 'B') { 
                b_r = i; b_c = j; 
            } 
        } 
    } 
    dfs(r_r, r_c, b_r, b_c, 1); 
    if (ans == 11) cout << 0;
    else cout << 1; 
}
