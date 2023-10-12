using pii = pair<int,int>;
class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    int ck[101][101];
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        memset(ck,0,sizeof(ck));
        vector<vector<int>> ans = {{rCenter, cCenter}};
        queue <pii> q;
        ck[rCenter][cCenter] = 1;
        q.push({rCenter, cCenter});
        while(q.size()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (0 > nr || nr >= rows || 0 > nc || nc >= cols) continue;
                if(ck[nr][nc]) continue;
                ck[nr][nc] = 1;
                ans.push_back({nr, nc});
                q.push({nr, nc});
            }
        }
        return ans;
    }
};