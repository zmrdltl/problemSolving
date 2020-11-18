/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const bs = (nums) => {
  const ans = [];
  if (nums.length < 3) return ans;

  for (let p = 0; p < nums.length - 1; p++) {
    if (p > 0 && nums[p - 1] === nums[p]) continue;
    let l = p + 1;
    let r = nums.length - 1;
    let sum = -1 * nums[p];
    while (l < r) {
      if (nums[l] + nums[r] == sum) {
        ans.push([nums[p], nums[l], nums[r]]);
        while (l < r && nums[l] == nums[l + 1]) l++;
        while (l < r && nums[r] == nums[r - 1]) r--;
        l++;
        r--;
      } else if (nums[l] + nums[r] < sum) {
        l++;
      } else {
        r--;
      }
    }
  }
  return ans;
};
var threeSum = function (nums) {
  let ans = [];
  nums.sort();
  console.log(nums);
  ans = bs(nums);
  return ans;
};
