use std::io;

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i32>().unwrap();
  for _ in 0..(n*5-n) {
    for _ in 0..n {
      print!("@");
    }
    println!("");
  }
  for _ in 0..n {
    for _ in 0..n*5 {
      print!("@");
    }
    println!("");
  }
}