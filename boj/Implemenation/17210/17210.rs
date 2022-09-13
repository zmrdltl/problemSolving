use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let door_num = line.trim().parse::<i64>().unwrap();

    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let mut way = line.trim().parse::<i64>().unwrap();

    if door_num > 5 {
        print!("Love is open door");
    } else {
        for _ in 1..door_num {
            way = 1 - way;
            println!("{}", way);
        }
    }
}
