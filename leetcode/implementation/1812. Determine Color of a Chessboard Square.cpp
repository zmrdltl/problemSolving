#define white true;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        vector <vector<bool>> boards(9, vector<bool>(9, false));
        bool color = white;
        for(int i = 1; i <= 8; i++) {
            for(int j = 1; j <= 8; j++) {
                boards[i][j] = color;
                color = !color;
            }
            color = !color;
        }

        int r = coordinates[0] - 'a' + 1;
        int c = coordinates[1] - '0';
        return boards[9-r][c];
    }
};