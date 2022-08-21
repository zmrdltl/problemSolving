use std::io;

fn main() {
    let mut ans = "뭐야?";
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let member = line.trim().parse::<i64>().unwrap();
    for i in 0..member {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("wrong io");
        line = line.trim().to_owned();
        if line.len() == 3 {
            if let Some(result) = line.find("anj") {
                ans = "뭐야;";
            }
        }
    }
    println!("{}", ans);
}
