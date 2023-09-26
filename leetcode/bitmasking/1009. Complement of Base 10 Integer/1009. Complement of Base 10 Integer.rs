impl Solution {
    pub fn get_bit_mask(n: i32) -> i32 {
        if n == 0 {
            return 1;
        }
        let mut mask = 1;
        while mask < n {
            mask = (mask << 1) | 1;
        }
        return mask;
    }
    pub fn bitwise_complement(n: i32) -> i32 {
        return n ^ Self::get_bit_mask(n);
    }
}