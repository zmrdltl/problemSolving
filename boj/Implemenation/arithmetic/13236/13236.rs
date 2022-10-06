use std::io;

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let mut n = line.trim().parse::<i64>().unwrap();
  print!("{} ", n);
  while n > 1 {
    if n % 2 > 0 {
      n = n * 3 + 1;
    }
    else {
      n = n / 2;
    }
    print!("{} ", n);
  }
}