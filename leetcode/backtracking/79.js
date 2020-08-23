let dx = [0, 0, -1, 1];
let dy = [1, -1, 0, 0];

const dfs = (i, j, cnt, board, word, visited) => {
  let x = i;
  let y = j;
  visited[x][y] = 1;

  if (cnt === word.length) return true;
  for (let i = 0; i < 4; i++) {
    let nx = x + dx[i];
    let ny = y + dy[i];
    if (nx < 0 || nx > board.length || ny < 0 || ny > board[0].length) continue;

    if (typeof visited[nx][ny] === "undefined" && word[cnt] === board[nx][ny]) {
      dfs(nx, ny, cnt + 1, board, word, visited);
    }
  }
};

const exist = (board, word) => {
  let visited = [[]];

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; i++) {
      visited[i][j] = 0;
    }
  }

  console.log(visited);

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      if (dfs(i, j, 0, board, word, visited) === false) return false;
    }
  }

  return true;
};

let board = [
  ["A", "B", "C", "E"],
  ["S", "F", "C", "S"],
  ["A", "D", "E", "E"],
];
console.log(exist(board, "ABCCED"));
