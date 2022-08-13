use std::io;
fn main() {
    loop {
        let mut line = String::new();
        let mut cheryl_point = 0;
        let mut tania_point = 0;
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();

        if line == "#".to_owned() {
            break;
        }

        let numbers: Vec<&str> = line.split_whitespace().collect();
        for i in numbers {
            if i == "*" {
                break;
            }
            let score;

            match i {
                "A" => score = "1",
                _ => score = i,
            }

            let score: i32 = score.parse().unwrap();

            if score % 2 > 0 {
                cheryl_point += 1;
            } else {
                tania_point += 1;
            }
        }

        if cheryl_point > tania_point {
            println!("Cheryl");
        } else if cheryl_point < tania_point {
            println!("Tania");
        } else {
            println!("Draw");
        }
    }
}
