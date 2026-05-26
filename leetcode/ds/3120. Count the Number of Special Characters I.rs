impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut lower = vec![false; 26];
        let mut upper = vec![false; 26];
        let mut ans = 0;
        for word_byte in word.bytes() {
            if word_byte.is_ascii_lowercase() {
                lower[(word_byte - b'a') as usize] = true;
            } else if word_byte.is_ascii_uppercase() {
                upper[(word_byte - b'A') as usize] = true;
            }
        }
        for i in 0..26 {
            if lower[i] && upper[i] {
                ans += 1;
            }
        }
        ans
    }
}
