use std::io;

fn main() {
    let mut ans: i64 = 0;
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let paper_len = line.trim().parse::<i64>().unwrap();
    for i in 0..paper_len {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();
        let numbers: Vec<i64> = line
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        for n in numbers {
            ans += n;
        }
    }
    println!("{}", ans);
}
