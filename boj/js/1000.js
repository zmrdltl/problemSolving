process.stdin.resume();
process.stdin.setEncoding("utf8");

let reader = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

reader.on("line", (line) => {
  data = line.split(" ").map((el) => parseInt(el));
  console.log(data[0] + data[1]);
});

//window에서 crtl+c 눌렀을 때 종료, mac에서는 command + c
reader.on("close", () => {
  reader.close();
  process.exit();
});
