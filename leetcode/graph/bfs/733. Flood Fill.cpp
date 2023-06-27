using pii = pair<int,int>;
class Solution {
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int height = image.size();
        int width = image[0].size();
        int originColor = image[sr][sc];
        vector<vector<int>> check(height,vector <int>(width,0));
        check[sr][sc] = 1;
        image[sr][sc] = color;
        queue <pii> q;
        q.push({sr,sc});
        
        while(q.size()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0 > nr || nr >= height || 0 > nc || nc >= width) continue;
                if(image[nr][nc] != originColor || check[nr][nc]) continue;
                check[nr][nc] = 1;
                image[nr][nc] = color;
                q.push({nr,nc});
            }
        }
        return image;
    }
};