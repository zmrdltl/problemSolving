process.stdin.resume();
process.stdin.setEncoding("utf8");

let reader = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

reader.on("line", (line) => {
  let n = parseInt(line.split(" ")[0]);
  const k = parseInt(line.split(" ")[1]);
  let ans = 0;
  if (n <= k) console.log(0);
  else {
    while (1) {
      let num = n;
      let cnt = 0;
      while (1) {
        if (num % 2) cnt += 1;
        num = parseInt(num / 2);
        if (num == 0) break;
      }
      if (cnt <= k) break;
      n += 1;
      ans += 1;
    }
    console.log(ans);
  }
  reader.close();
});
