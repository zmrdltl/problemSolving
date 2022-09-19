use std::{cmp, io};
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let n = line.trim().parse::<i64>().unwrap();
    let mut ans = 0;
    for i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        let numbers: Vec<i64> = line
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        let a = numbers[0 as usize];
        let d = numbers[1 as usize];
        let g = numbers[2 as usize];
        let mut score = a * (d + g);
        if a == d + g {
            score *= 2;
        }
        ans = cmp::max(ans, score);
    }
    print!("{}", ans);
}
