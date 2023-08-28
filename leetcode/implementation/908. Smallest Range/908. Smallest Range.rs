use::std::cmp;
impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let mut minNum = 0x3f3f3f3f;
        let mut maxNum = 0;
        for n in nums {
            minNum = cmp::min(minNum, n);
            maxNum = cmp::max(maxNum, n);
        }
        if maxNum - k <= minNum + k {
            return 0;
        }
        return maxNum - k - (minNum + k);
    }
}