let pad = {
  2: ["a", "b", "c"],
  3: ["d", "e", "f"],
  4: ["g", "h", "i"],
  5: ["j", "k", "l"],
  6: ["m", "n", "o"],
  7: ["p", "q", "r", "s"],
  8: ["t", "u", "v"],
  9: ["w", "x", "y", "z"],
};
let depth = 0;
let ans = [];
const dfs = (alpha, depth, s) => {
  let length = alpha.length;
  if (depth === length) {
    ans.push(s);
    return;
  }

  for (let i = 0; i < alpha[depth].length; i++) {
    dfs(alpha, depth + 1, s + alpha[depth][i]);
  }
};

const letterCombinations = (digits) => {
  ans = [];
  if (digits === "") return ans;
  let alpha = [];

  for (let i = 0; i < digits.length; i++) {
    alpha.push(pad[digits[i]]);
  }

  dfs(alpha, depth, "", ans);
  return ans;
};

// process.stdin.resume();
// process.stdin.setEncoding("utf8");

// let reader = require("readline").createInterface({
//   input: process.stdin,
//   output: process.stdout,
// });

// reader.on("line", (line) => {
//   //data = line.split(" ").map((el) => parseInt(el));
//   console.log(letterCombinations(line));
// });

// //window에서 crtl+c 눌렀을 때 종료, mac에서는 command + c
// reader.on("close", () => {
//   reader.close();
//   process.exit();
// });
