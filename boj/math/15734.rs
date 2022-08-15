use std::{cmp, io};

fn get_num(s: &str) -> i32 {
    s.to_owned().parse::<i32>().unwrap()
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let line: Vec<&str> = line.trim().split(" ").collect::<Vec<_>>();

    let l = get_num(line[0]);
    let r = get_num(line[1]);
    let a = get_num(line[2]);
    let all = l + r + a;
    let diff = i32::abs(l - r);
    let surplus = diff - a;

    if surplus < 0 {
        let surplus = a - diff;
        if surplus % 2 > 0 {
            print!("{}", all - 1);
        } else {
            print!("{}", all);
        }
    } else {
        print!("{}", all - i32::abs(cmp::min(l, r) + a - cmp::max(l, r)));
    }
}
