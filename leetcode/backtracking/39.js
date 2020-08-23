var arr = new Array();
const dfs = (sum, target, idx, cans, ans) => {
  let length = cans.length;

  if (sum === target) {
    arr.push(ans.slice(0));
    return;
  }

  for (let i = idx; i < length; i++) {
    if (sum + cans[i] <= target) {
      ans.push(cans[i]);
      dfs(sum + cans[i], target, i, cans, ans);
      ans.pop();
    }
  }
};

const combinationSum = (candidates, target) => {
  arr = new Array();
  dfs(0, target, 0, candidates, []);
  return arr;
};

arr = combinationSum([2, 3, 6, 7], 7);
console.log(arr);
