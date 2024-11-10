function solution(s) {
  var answer = "";
  let big = -2000000000;
  let mini = 2000000000;
  s = s.split(" ");
  for (let i = 0; i < s.length; i++) {
    let num = parseInt(s[i]);
    if (big < num) big = num;
    if (mini > num) mini = num;
  }
  answer += mini.toString() + " ";
  answer += big.toString();

  return answer;
}
