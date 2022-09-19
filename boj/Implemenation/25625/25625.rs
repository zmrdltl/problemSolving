use std::io;
fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let nums: Vec<i64> = line.trim().split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect();
  let x = nums[0 as usize];
  let y = nums[1 as usize];
  if x > y {
    print!("{}", x + y);
  }
  else {
    print!("{}", y - x);
  }
}