function solution(dartResult) {
  let answer = 0;
  let flag1 = 0;
  let flag2 = 0;
  let score = 0;
  let tmp = "";
  for (let i = 0; i < dartResult.length; i++) {
    while (1) {
      tmp += dartResult[i];
      if (
        dartResult[i] === "S" ||
        dartResult[i] === "T" ||
        dartResult[i] === "D"
      ) {
        score = parseInt(tmp);
        tmp = "";
        break;
      } else if (dartResult[i] === "*" || dartResult[i] === "#") {
        tmp = "";
        break;
      }
      i += 1;
    }
    if (dartResult[i] === "S") {
      answer += score;
    } else if (dartResult[i] === "D") {
      answer += score * score;
    } else if (dartResult[i] === "T") {
      answer += score * score * score;
    } else if (dartResult[i] === "*") {
      if (flag1) {
        answer *= 4;
      } else {
        flag1 += 1;
        answer *= 2;
      }
    } else {
      if (flag1) {
        score *= -2;
      } else {
        score *= -1;
      }
    }
    if (dartResult[i + 1] !== "*" && dartResult[i + 1] !== "#") answer += score;
    console.log("스코어", score);
    console.log(answer);
  }
  return answer;
}

console.log(solution("1S2D*3T"));
