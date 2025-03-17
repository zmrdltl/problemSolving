use std::cmp::max;

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut maxWealth = 0;
        for i in 0..accounts.len() {
            let mut wealth = 0;
            for j in 0..accounts[i].len() {
                wealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, wealth);
        }

        return maxWealth;
    }
}
