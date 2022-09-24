use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let n = line.trim().parse::<i64>().unwrap();
    println!("{}", n);
    print!("{}", 1);
}
