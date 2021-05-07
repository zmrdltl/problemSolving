function solution(s) {
  let answer = [];
  let M = new Map();
  s = s.substr(1, s.length - 2);
  let refined = [];
  refined = s
    .split("},{")
    .map((v) => v.replace(/\{|\}/g, ""))
    .map((v) => v.split(",").map((v) => +v))
    .sort((a, b) => a.length - b.length);

  for (let i = 0; i < refined.length; i++) {
    for (let j = 0; j < refined[i].length; j++) {
      if (M.has(refined[i][j]) === false) {
        M.set(refined[i][j], 1);
        answer.push(parseInt(refined[i][j]));
        break;
      }
    }
  }
  return answer;
}
