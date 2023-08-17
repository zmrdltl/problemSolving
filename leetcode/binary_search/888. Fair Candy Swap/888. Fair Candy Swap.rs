impl Solution {
    pub fn fair_candy_swap(alice_sizes: Vec<i32>, bob_sizes: Vec<i32>) -> Vec<i32> {
        let alice_sum: i32 = alice_sizes.iter().sum();
        let bob_sum: i32 = bob_sizes.iter().sum();
        let diff: i32 = alice_sum - (alice_sum + bob_sum) / 2;
        let mut bob_sorted = bob_sizes.clone();
        bob_sorted.sort();

        for &a in &alice_sizes {
            let key = a - diff;
            match bob_sorted.binary_search(&key){
                Ok(idx) => {
                    if a - bob_sorted[idx] == diff {
                        return vec![a, bob_sorted[idx]];
                    }
                }
                _ => {
                    continue;
                }
            }
        }
        vec![]
    }
}