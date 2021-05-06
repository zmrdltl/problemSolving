const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];
let n;

function bfs(board) {
  let ans = 0x3f3f3f3f;
  let q = [[0, 0, 0, -1]];
  board[0][0] = 1;

  while (q.length !== 0) {
    const x = q[0][0];
    const y = q[0][1];
    const cost = q[0][2];
    const dir = q[0][3];
    q.shift();
    // if (x == n - 1 && y == n - 1) {
    //   ans = Math.min(ans, cost);
    //   continue;
    // }
    for (let k = 0; k < 4; k++) {
      const nx = x + dx[k];
      const ny = y + dy[k];
      let nc = 0;
      if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;
      if (board[nx][ny] === 1) continue;

      if (dir === -1 || dir === k) nc = cost + 100;
      else if (dir !== k) nc = cost + 600;

      if (board[nx][ny] === 0 || board[nx][ny] >= nc) {
        board[nx][ny] = nc;
        q.push([nx, ny, nc, k]);
      }
    }
  }
  return board[n - 1][n - 1];
}

function solution(board) {
  n = board.length;
  return bfs(board);
}
