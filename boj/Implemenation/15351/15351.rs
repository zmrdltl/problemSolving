use std::io;

fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i64>().unwrap();
  for _ in 0..n {
    let mut score = 0;
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let life = line.trim();
    for c in life.chars() {
      if c == ' ' {
        continue;
      }
      score += c as usize - 'A' as usize + 1;
    }
    if score == 100 {
      println!("PERFECT LIFE");
    }
    else {
      println!("{}", score);
    }
  }
}