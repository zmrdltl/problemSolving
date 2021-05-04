//진수 수개수 참가인원 튜브순서
function solution(n, t, m, p) {
  let num = "";
  let tmp = "";
  for (let i = 0; i <= t * m; i++) num += i.toString(n);
  for (let i = p - 1; i < num.length; i += m) tmp += num[i];
  return tmp.substring(0, t).replace(/[a-z]/g, (match) => match.toUpperCase());
}
