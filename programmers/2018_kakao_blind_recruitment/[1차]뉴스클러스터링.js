function isAlpha(char) {
  const pattern = /^[a-zA-Z]+$/;
  return pattern.test(char) ? true : false;
}

function makeSet(str) {
  const set = [];
  let tmp = str[0];
  for (let i = 1; i < str.length; i++) {
    if (isAlpha(str[i])) {
      tmp += str[i];
    } else {
      tmp = "";
      continue;
    }
    if (tmp !== "" && tmp.length === 2) set.push(tmp.toLowerCase());
    tmp = str[i];
  }
  return set;
}

function solution(str1, str2) {
  const set1 = makeSet(str1);
  const set2 = makeSet(str2);

  const set = new Set([...set1, ...set2]);
  console.log(set);
  let interactSetSize = 0;
  let unionSetSize = 0;

  set.forEach((item) => {
    const value1 = set1.filter((x) => x === item).length;
    const value2 = set2.filter((x) => x === item).length;
    unionSetSize += Math.max(value1, value2);
    interactSetSize += Math.min(value1, value2);
  });
  return unionSetSize === 0
    ? 65536
    : parseInt((interactSetSize / unionSetSize) * 65536);
}

console.log(solution("handshake", "shake hands"));
