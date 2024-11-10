function solution(n) {
  n = parseInt(n);
  let k = n.toString(2);
  let cnt = 0;
  for (let i = 0; i < k.length; i++) {
    if (k[i] === "1") cnt++;
  }
  for (let i = n + 1; i <= 2000000; i++) {
    let s = i.toString(2);
    let c = 0;
    for (let j = 0; j < s.length; j++) if (s[j] === "1") c++;
    if (c === cnt) return parseInt(s, 2);
  }
}
