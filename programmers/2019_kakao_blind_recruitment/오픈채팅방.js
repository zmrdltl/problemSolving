function solution(record) {
  var answer = [];
  const map = new Map();
  for (let i = 0; i < record.length; i++) {
    record[i] = record[i].split(" ");
    const id = record[i][1];
    const nickName = record[i][2];
    if (nickName) map.set(id, nickName);
  }

  for (let i = 0; i < record.length; i++) {
    const stat = record[i][0];
    const id = record[i][1];

    if (stat === "Enter") {
      answer.push(map.get(id) + "님이 들어왔습니다.");
    } else if (stat === "Leave") {
      answer.push(map.get(id) + "님이 나갔습니다.");
    }
  }
  return answer;
}
