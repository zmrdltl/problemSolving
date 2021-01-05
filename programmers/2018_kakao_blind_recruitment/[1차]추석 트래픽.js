function solution(lines) {
  var answer = 0;
  const arr = [];
  const time = [];
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i].split(" ");
    const endSecond =
      Number(line[1].substring(0, 2)) * 3600 +
      Number(line[1].substring(3, 5)) * 60 +
      Number(line[1].substring(6, 12));
    const duration = Number(line[2].substring(0, line[2].length - 1));
    const startSecond = endSecond - duration + 0.001;
    arr.push([startSecond, endSecond]);
    time.push(startSecond, endSecond);
  }
  time.sort();
  for (let i = 0; i < time.length; i++) {
    const start = time[i];
    const end = time[i] + 1.0;
    let count = 0;
    for (let j = 0; j < arr.length; j++) {
      const startSecond = arr[j][0];
      const endSecond = arr[j][1];
      if (
        (start <= startSecond && startSecond < end) ||
        (start <= endSecond && endSecond < end) ||
        (start >= startSecond && endSecond >= end)
      )
        count += 1;
    }
    answer = Math.max(answer, count);
  }
  return answer;
}
