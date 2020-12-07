/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const bs = (nums) => {
  const ans = [];
  if (nums.length < 3) return ans;

  let r = nums.length - 1;
  for (let p = 0; p < nums.length - 2; p++) {
    if (p > 0 && nums[p - 1] == nums[p]) continue;
    let l = p + 1;
    let sum = -nums[p];
    while (l < r) {
      if (nums[l] + nums[r] == sum) {
        ans.push([-sum, nums[l], nums[r]]);
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
  nums.sort(function (a, b) {
    return a - b;
  });
  console.log(nums);
  const ans = bs(nums);
  return ans;
};
