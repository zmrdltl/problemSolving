use std::io;

pub fn print_edge(n:i64){
  for _ in 0..n {
    for _ in 0..n*5 {
      print!("@");
    }
    println!("");
  }
}

pub fn print_mid(n:i64){
  for _ in 0..n*3 {
    for _ in 0..n {
      print!("@");
    }
    println!("");
  }
}

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n:i64 = line.trim().parse::<i64>().unwrap();

  print_edge(n);
  print_mid(n);
  print_edge(n);
}