impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let mut sum: i32 = arr.iter().sum();
        if sum % 3 != 0 return false;
        let piv_sum = sum / 3;
        sum = 0;
        let pivIdx:Vec<i32> = Vec::new();
        for (i, &num) in arr.iter().enumerate() {
            sum += num;
            if sum == piv_sum {
                piv_idx.push(i);
                sum = 0;
            }
        }
        piv_idx.len() >= 3
    }
}