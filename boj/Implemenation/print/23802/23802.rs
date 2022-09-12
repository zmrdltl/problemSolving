use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let n = line.trim().parse::<i64>().unwrap();
    for _ in 0..n {
        for _ in 0..n * 5 {
            print!("@");
        }
        println!();
    }
    for _ in 0..n * 4 {
        for _ in 0..n {
            print!("@");
        }
        println!();
    }
}
