function trim(n, arr) {
  let tmp = "";
  for (let i = 0; i < n - arr.length; i++) {
    tmp += "0";
  }
  for (let i = 0; i < arr.length; i++) {
    tmp += arr[i];
  }
  return tmp;
}
function getFullArr(n, map1, map2) {
  let tmp = "";
  let arr = "";
  for (let i = 0; i < n; i++) {
    if (map1[i] === "1" || map2[i] === "1") tmp += "1";
    else if (map1[i] == "0" && map2[i] == "0") {
      tmp += "0";
    }
  }

  for (let i = 0; i < n; i++) {
    if (tmp[i] === "1") arr += "#";
    else arr += " ";
  }
  return arr;
}

function solution(n, arr1, arr2) {
  const answer = [];
  for (let i = 0; i < n; i++) {
    let map1 = parseInt(arr1[i]).toString(2);
    map1 = trim(n, map1);
    let map2 = parseInt(arr2[i]).toString(2);
    map2 = trim(n, map2);
    answer.push(getFullArr(n, map1, map2));
  }
  return answer;
}

console.log(solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]));
