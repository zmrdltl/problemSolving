use std::io;

fn main() {
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i32>().unwrap();

  for _ in 0..n+2 {
    print!("@");
  }
  println!("");

  for _ in 0..n {
    for j in 0..n+2{
      if j == 0 || j == n + 1 {
        print!("@");
      }
      else {
        print!(" ");
      }
    }
    println!("");
  }

  for _ in 0..n+2 {
    print!("@");
  }
}
