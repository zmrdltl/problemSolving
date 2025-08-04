use std::cmp::max;

impl Solution {
    pub fn gcd(a: i32, b: i32) -> i32 {
        if (b == 0) {
            return a;
        }
        return Self::gcd(b, a % b);
    }

    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        if let (Some(&max_num), Some(&min_num)) = (nums.iter().max(), nums.iter().min()) {
            return Self::gcd(max_num, min_num);
        } else {
            return 0;
        }
    }
}
