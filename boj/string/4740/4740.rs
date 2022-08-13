use std::io;

fn main() {
    loop {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");

        if line == "***\n" {
            break;
        }

        for i in 1..line.len() {
            print!("{}", line.as_bytes()[line.len() - i - 1] as char);
        }
        println!("");
    }
}
