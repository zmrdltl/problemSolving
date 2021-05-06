let ans = 0x3f3f3f3f;
let n, num;
function dfs(depth, sum) {
  if (depth > 8) return -1;
  if (sum == num) {
    ans = Math.min(ans, depth);
    return;
  }
  let tmp = 0;

  for (let i = 0; i < 8; i++) {
    tmp = tmp * 10 + n;
    dfs(depth + i + 1, sum + tmp);
    dfs(depth + i + 1, sum - tmp);
    dfs(depth + i + 1, sum * tmp);
    dfs(depth + i + 1, parseInt(sum / tmp));
  }
}

function solution(N, number) {
  n = N;
  num = number;
  ans = 0x3f3f3f3f;
  dfs(0, 0);
  if (ans > 8) return -1;
  return ans;
}

console.log(solution(5, 12));
