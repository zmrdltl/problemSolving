struct Coord {
    int row, col;
};
class Solution {
public:
    int countIntDirection(vector<vector<char>>& board, Coord start, Coord delta) {
        int count = 0;
        for(int i = 1;; i++) {
            int row = start.row + i * delta.row;
            int col = start.col + i * delta.col;
            if(0 > row || row >= board.size() || 0 > col || col >= board[0].size()) break;
            if(board[row][col] == 'B') break;
            if(board[row][col] == 'p') {
                count++;
                break;
            }
        }
        return count;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        Coord rookCoord;
        int ans = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'R') rookCoord = {i, j};
            }
        }
        ans += countIntDirection(board, rookCoord, {0,-1}); //좌
        ans += countIntDirection(board, rookCoord, {0, 1}); //우
        ans += countIntDirection(board, rookCoord, {-1,0}); //상
        ans += countIntDirection(board, rookCoord, {1, 0}); //하
        return ans;
    }
};