function removeZero(convertedWord, answer) {
  let tmp = "";
  for (let i = 0; i < convertedWord.length; i++) {
    if (convertedWord[i] !== "0") tmp += convertedWord[i];
    else answer[1] += 1;
  }
  answer[0] += 1;
  return tmp;
}

function solution(s) {
  const answer = [0, 0];
  let convertedWord = s;
  while (1) {
    let word = removeZero(convertedWord, answer);
    convertedWord = word.length.toString(2);
    if (convertedWord === "1") break;
  }
  return answer;
}

console.log(solution("0111010"));
