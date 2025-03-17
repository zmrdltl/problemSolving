impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::with_capacity(nums.len());
        let mut sum = 0;
        for i in 0..nums.len() {
            sum += nums[i];
            result.push(sum);
        }
        result
    }
}
