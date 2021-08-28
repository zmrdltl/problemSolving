process.stdin.resume();
process.stdin.setEncoding("utf8");

let reader = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

reader.on("line", (line) => {
  data = line.split(" ");
  let ans = [];
  let num = [];
  for (let i = 2; i <= 36; i++) {
    for (let j = 2; j <= 36; j++) {
      if (i == j) continue;
      if (parseInt(data[0], i) == parseInt(data[1], j)) {
        ans.push(parseInt(data[0], i));
        num.push(i);
        num.push(j);
      }
    }
  }
  if (ans.length == 0) console.log("Impossible");
  else if (ans.length >= 2) console.log("Multiple");
  else {
    console.log(ans[0], num[0], num[1]);
  }
  reader.close();
  process.exit();
});
