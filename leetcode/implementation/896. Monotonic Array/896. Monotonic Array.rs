impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut isIncrease = -1;
        for i in 0..nums.len()-1 {
            if nums[i] == nums[i+1] {
                continue;
            }
            if nums[i] < nums[i+1] {
                if isIncrease == 0 {
                    return false;
                }
                isIncrease = 1;
            } else {
                if isIncrease == 1 {
                    return false;
                }
                isIncrease = 0;
            }
        }
        return true
    }
}