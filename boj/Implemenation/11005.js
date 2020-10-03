process.stdin.resume();
process.stdin.setEncoding("utf8");

let reader = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

reader.on("line", (line) => {
  const n = line.split(" ")[0];
  const b = line.split(" ")[1];

  const answer = parseInt(n, 10).toString(b);
  for (let i = 0; i < answer.length; i++) {
    if ("a" <= answer[i] && answer[i] <= "z") {
      process.stdout.write(answer[i].toUpperCase());
    } else process.stdout.write(answer[i]);
  }
  reader.close();
});
