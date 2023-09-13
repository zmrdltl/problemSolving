use std::collections::HashMap;
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let mut m = HashMap::new();
        let mut ans = 1;
        for n in nums {
            let mVal = m.get(&n);
            if let Some(_) = mVal {
                ans = n;
                break;
            } else {
                m.insert(n, 1);
            }
        }
        return ans;
    }
}