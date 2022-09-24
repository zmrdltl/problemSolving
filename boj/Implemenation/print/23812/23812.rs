use std::io;


pub fn print_other(n: i64){
  for _ in 0..n {
    for j in 0..n*5 {
      if j < n || j >= n * 4 {
        print!("@");
      }
      else {
        print!(" ");
      }
    }
    println!();
  }
}

pub fn print_square(n: i64){
  for _ in 0..n {
    for _ in 0..n*5{
      print!("@");
    }
    println!();
  }
}

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i64>().unwrap();
  print_other(n);
  print_square(n);
  print_other(n);
  print_square(n);
  print_other(n);
}