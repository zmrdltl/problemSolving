function solution(dartResult) {
  const answer = [];
  let number = "";
  for (const result of dartResult) {
    if (result === "*") {
      answer[answer.length - 1] *= 2;
      if (answer.length > 1) {
        answer[answer.length - 2] *= 2;
      }
      continue;
    }
    if (result === "#") {
      answer[answer.length - 1] *= -1;
      continue;
    }
    if (result === "S") {
      answer.push(Math.pow(Number.parseInt(number), 1));
      number = "";
      continue;
    }
    if (result === "D") {
      answer.push(Math.pow(Number.parseInt(number), 2));
      number = "";
      continue;
    }
    if (result === "T") {
      answer.push(Math.pow(Number.parseInt(number), 3));
      number = "";
      continue;
    }
    number += result;
  }
  let sum = 0;
  answer.forEach((n) => (sum = sum + n));
  return sum;
}