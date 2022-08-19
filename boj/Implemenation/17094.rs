use std::io;
fn main() {
    let mut one = 0;
    let mut two = 0;
    let mut str_len = String::new();
    io::stdin().read_line(&mut str_len).expect("wrong io");
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("wrong io");
    for c in s.chars() {
        if c == '2' {
            one += 1;
        }
        if c == 'e' {
            two += 1;
        }
    }
    if one > two {
        print!("2");
    }
    else if one < two {
        print!("e");
    }
    else {
        print!("yee");
    }
}
