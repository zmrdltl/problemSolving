class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector <vector<char>> board(3, vector<char>(3));
        for(int i = 0; i < moves.size(); i++) {
            if(i % 2 == 0) board[moves[i][0]][moves[i][1]] = 'X';
            else board[moves[i][0]][moves[i][1]] = 'O';
        }
        
        int xCnt = 0, oCnt = 0;
        // ㅡ, | 검사
        for(int i = 0; i < 3; i++) {
            xCnt = 0, oCnt = 0;
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X') xCnt++;
                else if(board[i][j] == 'O') oCnt++;
                if(xCnt == 3 && oCnt == 3) return "Draw";
                if(xCnt == 3) return "A";
                if(oCnt == 3) return "B";
            }
            xCnt = 0, oCnt = 0;
            for(int j = 0; j < 3; j++) {
                if(board[j][i] == 'X') xCnt++;
                else if(board[j][i] == 'O') oCnt++;
                if(xCnt == 3 && oCnt == 3) return "Draw";
                if(xCnt == 3) return "A";
                if(oCnt == 3) return "B";
            }
        }
        // '\' 검사
        xCnt = 0, oCnt = 0;
        for(int i = 0; i < 3; i++) {
            if(board[i][i] == 'X') xCnt++;
            else if(board[i][i] == 'O') oCnt++;
            if(xCnt == 3) return "A";
            if(oCnt == 3) return "B";
        }
        // '/' 검사
        xCnt = 0, oCnt = 0;
        for(int i = 0; i < 3; i++) {
            if(board[i][2-i] == 'X') xCnt++;
            else if(board[i][2-i] == 'O') oCnt++;
            if(xCnt == 3) return "A";
            if(oCnt == 3) return "B";
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};