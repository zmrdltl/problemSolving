use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let n = line.trim().parse::<i64>().unwrap();

    for _ in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        let v: Vec<i64> = line
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        if (v[0 as usize] <= 2 && v[1 as usize] <= 1) || (v[0 as usize] <= 1 && v[1 as usize] <= 2)
        {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}
