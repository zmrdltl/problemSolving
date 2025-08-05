impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, baskets: Vec<i32>) -> i32 {
        let mut checked = vec![false; baskets.len()];

        fruits.iter().for_each(|fruit| {
            if let Some((j, _)) = baskets
                .iter()
                .enumerate()
                .find(|(j, basket)| fruit <= basket && !checked[*j])
            {
                checked[j] = true;
            }
        });
        let unplaced = checked.iter().filter(|&&x| !x).count() as i32;
        unplaced
    }
}
