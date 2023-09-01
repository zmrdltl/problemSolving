impl Solution {
    pub fn sort_array_by_parity_ii(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = Vec::new();
        let mut odd = Vec::new();
        let mut even = Vec::new();
        for n in nums {
            if n % 2 == 1 {
                odd.push(n);
            } else {
                even.push(n);
            }
        }
         while !odd.is_empty() || !even.is_empty() {
            if let Some(e) = even.pop() {
                ans.push(e);
            }
            if let Some(o) = odd.pop() {
                ans.push(o);
            }
        }
        ans
    }
}