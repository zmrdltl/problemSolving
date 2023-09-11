impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let sz = s.len();
        let mut l = 0;
        let mut r = sz as i32;
        let mut ans:Vec<i32> = Vec::new();
        println!("{:?}",s.chars());
        for c in s.chars() {
            if c == 'I' {
                ans.push(l);
                l += 1;
            } else {
                ans.push(r);
                r -= 1;
            }
        }
        ans.push(l);
        return ans;
    }
}