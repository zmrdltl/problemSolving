use std::collections::HashMap;

impl Solution {
    pub fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a
        } else {
            Self::gcd(b, a%b)
        }
    }

    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut m = HashMap::new();
        for d in deck {
            let count = m.entry(d).or_insert(0);
            *count += 1;
        }
        let mut g = 1;
        g = *m.iter().next().map(|(_,v)| v).unwrap();

        for &val in m.values() {
            g = Self::gcd(g, val);
        }

        return g > 1;
    }
}