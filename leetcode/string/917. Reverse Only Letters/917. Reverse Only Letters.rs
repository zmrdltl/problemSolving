impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let mut alphas: Vec<char> = s.chars().filter(|&c| c.is_ascii_alphabetic()).collect();
        let mut iter = alphas.into_iter().rev();

        s.chars().map(|c| {
            if !c.is_ascii_alphabetic() {
                c
            } else {
                iter.next().unwrap()
            }
        }).collect()
    }
}