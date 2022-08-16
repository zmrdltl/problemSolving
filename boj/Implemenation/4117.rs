use std::{cmp, io};
//TODO
fn main() {
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();
        let numbers: Vec<i32> = line
            .split_whitespace()
            .map(|num| num.parse::<i32>().unwrap())
            .collect();
        if numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0 {
            break;
        }
        let n = numbers[0];
        let t1 = numbers[1];
        let t2 = numbers[2];
        let t3 = numbers[3];
        let mut last1 = t1 - t2;
        let mut last2 = t3 - t2;
        if last1 < 0 {
            last1 += n;
        }
        if last2 < 0 {
            last2 += n;
        }
        let mut ans = n * 2 + t1 + n + last1 + last2;
        println!("{:#?}", cmp::max(ans, ans));
    }
}
