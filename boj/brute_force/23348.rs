use std::{cmp, io};

fn main() {
    let mut ans: i64 = 0;
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");

    let scores: Vec<i64> = line
        .split_whitespace()
        .map(|num| num.parse::<i64>().unwrap())
        .collect();

    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");

    let club_numbers = line.trim().parse::<i64>().unwrap();

    for i in 0..club_numbers {
        let mut score: i64 = 0;

        for k in 0..3 {
            let mut line = String::new();
            io::stdin().read_line(&mut line).expect("wrong io");
            let tech_freq: Vec<i64> = line
                .split_whitespace()
                .map(|num| num.parse::<i64>().unwrap())
                .collect();
            for j in 0..3 {
                score += tech_freq[j] * scores[j];
            }
        }

        ans = cmp::max(ans, score);
    }
    print!("{}", ans);
}
