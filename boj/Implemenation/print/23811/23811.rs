use std::io;

pub fn print_long(n: i64){
  for _ in 0..n {
    for _ in 0..n*5{
      print!("@");
    }
    println!();
  }
}

pub fn print_short(n: i64){
  for _ in 0..n {
    for _ in 0..n {
      print!("@");
    }
    println!();
  }
}

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i64>().unwrap();
  print_long(n);
  print_short(n);
  print_long(n);
  print_short(n);
  print_long(n);
}