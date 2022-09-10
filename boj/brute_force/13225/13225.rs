use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let mut n = line.trim().parse::<i32>().unwrap();
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        let num = line.trim().parse::<i32>().unwrap();
        let mut divisors = vec![];
        for i in 1..num + 1 {
            if num % i == 0 {
                divisors.push(i);
            }
        }
        println!("{} {}", num, divisors.len());
        n -= 1;
        if n == 0 {
            break;
        }
    }
}
