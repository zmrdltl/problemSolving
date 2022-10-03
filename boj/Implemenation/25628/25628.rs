use std::{io, cmp};
fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let numbers:Vec<i64> = line.trim().split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect();
  println!("{}", cmp::min(numbers[0 as usize] / 2, numbers[1 as usize]));
}