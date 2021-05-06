let comb = [];
let num = [];
let ck = Array.from({ length: 50 }, (undefined, i) => 0);
let primeCk = Array.from({ length: 100001 }, (undefined, i) => 0);
let answer = 0;
function makePrime() {
  for (let i = 2; i <= 100000; i++) {
    if (primeCk[i] == 0) {
      for (let j = i + i; j <= 100000; j += i) primeCk[j] = 1;
    }
  }
}
makePrime();

function dfs(depth, idx) {
  if (depth === 3) {
    let sum = 0;
    for (let i = 0; i < comb.length; i++) sum += comb[i];
    if (primeCk[sum] === 0) answer++;
    return;
  }
  for (let i = idx; i < num.length; i++) {
    if (ck[i]) continue;
    ck[i] = 1;
    comb.push(num[i]);
    dfs(depth + 1, i + 1);
    comb.pop();
    ck[i] = 0;
  }
}
function solution(nums) {
  num = nums;
  answer = 0;
  dfs(0, 0);
  return answer;
}
