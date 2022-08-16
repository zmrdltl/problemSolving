use std::io;
fn main() {
    let mut test_case = String::new();
    io::stdin().read_line(&mut test_case).expect("wrong io");
    let test_case = test_case.trim().parse::<i64>().unwrap();
    for i in 1..test_case + 1 {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();
        let numbers: Vec<i64> = line
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        let x = numbers[0] / numbers[1];
        let y = numbers[0] % numbers[1];
        print!("Case {}: ", i);
        if x == 0 && y != 0 {
            println!("{}/{}", y, numbers[1]);
        } else if x == 0 && y == 0 {
            println!("0");
        } else if y == 0 {
            println!("{}", x);
        } else {
            println!("{} {}/{}", x, y, numbers[1]);
        }
    }
}
