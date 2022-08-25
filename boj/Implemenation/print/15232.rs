use std::{cmp, io};

fn main() {
  let mut line = String::new();
  let mut line2 = String::new();

  io::stdin().read_line(&mut line).expect("wrong io");
  io::stdin().read_line(&mut line2).expect("wrong io");
  
  let r = line.trim().parse::<i32>().unwrap();
  let c = line2.trim().parse::<i32>().unwrap();

  for i in 0..r {
    for j in 0..c {
      print!("*");
    }
    println!();
  }  
}
