#include <string>
#include <vector>
using namespace std;
int ans, N;
vector <int> board;
int isOk(int tuple) {
    for (int col = 0; col < tuple; col++){
        if (board[tuple] == board[col] || abs(board[tuple] - board[col]) ==  tuple - col )
            return false;
    }
    return true;
}
 
void dfs(int tuple) {
    if (tuple == N) ans += 1;
    else{
        for (int col = 0; col < N; col++){
            board[tuple] = col;
            if (isOk(tuple)) dfs(tuple +1);
        }
    }
}


int solution(int n) {
    ans = 0;
    vector <int> b (n*n,0);
    N = n;
    board = b;
    dfs(0);
    return ans;
}

