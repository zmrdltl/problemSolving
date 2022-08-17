use std::io;

fn main() {
    let mut month = vec![0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut test_case = String::new();
    io::stdin().read_line(&mut test_case).expect("wrong io");
    let test_case = test_case.trim().parse::<i32>().unwrap();
    for i in 1..test_case + 1 {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();
        let numbers: Vec<i32> = line
            .split_whitespace()
            .map(|num| num.parse::<i32>().unwrap())
            .collect();
        let year = numbers[0];
        let m = numbers[1];
        if (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) {
            month[2] = 29;
        } else {
            month[2] = 28;
        }
        if m == 1 {
            println!("{} 12 31", year - 1);
        } else {
            println!("{} {} {}", year, m - 1, month[(m - 1) as usize]);
        }
    }
}
