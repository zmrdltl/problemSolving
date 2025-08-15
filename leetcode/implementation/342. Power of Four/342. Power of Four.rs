impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n == 0 {
            return false;
        }
        for i in 0..=16 {
            if 4_i32.pow(i) == n {
                return true;
            }
        }
        return false;
    }
}
