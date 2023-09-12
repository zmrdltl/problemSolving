impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let mut columns_to_delete = 0;

        for i in 0..strs[0].len() {
            for j in 0..strs.len() - 1 {
                if strs[j].as_bytes()[i] > strs[j + 1].as_bytes()[i] {
                    columns_to_delete += 1;
                    break;
                }
            }
        }

        columns_to_delete
    }
}
