use std::io;
fn main() {
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let t = line.trim().parse::<f64>().unwrap();
  println!("{}", (t/2.0 * t/2.0).round());
}