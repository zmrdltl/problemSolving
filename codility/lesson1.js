function solution(N) {
  let answer = 0;
  N = parseInt(N).toString(2);
  for (let i = 0; i < N.length; i++) {
    let cnt = 0;
    let pivot = i;
    if (N[i] == "0") {
      while (1) {
        if (N[pivot] === "1" || pivot === N.length) break;
        else cnt += 1;
        pivot += 1;
      }
      i = pivot;
    }
    if (pivot === N.length && N[pivot - 1] === "0") cnt = 0;
    answer = Math.max(answer, cnt);
  }
  return answer;
}
