function solution(expression) {
  const results = [];

  const priority = [
    ["+", "-", "*"],
    ["+", "*", "-"],
    ["-", "+", "*"],
    ["-", "*", "+"],
    ["*", "+", "-"],
    ["*", "-", "+"],
  ];

  for (let op of priority) {
    const tmp = expression.split(/(\D)/);
    console.log(tmp);
    for (let exp of op) {
      while (tmp.includes(exp)) {
        const opIdx = tmp.indexOf(exp);
        tmp.splice(
          opIdx - 1,
          3,
          eval(tmp.slice(opIdx - 1, opIdx + 2).join(""))
        );
      }
    }
    results.push(Math.abs(tmp[0]));
  }
  return Math.max(...results);
}

solution("100-200*300-500+20");
