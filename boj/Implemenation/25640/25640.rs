use std::io;
fn main(){
  let mut line = String::new();
  let mut ans = 0;
  io::stdin().read_line(&mut line).expect("wrong io");
  let jinhoMBTI = line.trim();
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i64>().unwrap();
  for _ in 0..n {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let friendMBTI = line.trim();
    if jinhoMBTI == friendMBTI {
      ans+=1;
    }
  }
  print!("{}", ans);
}