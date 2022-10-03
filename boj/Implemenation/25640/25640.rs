use std::io;
fn main(){
  let mut line = String::new();
  let mut ans = 0;
  io::stdin().read_line(&mut line).expect("wrong io");
  let jinho_mbti = line.trim();
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let n = line.trim().parse::<i64>().unwrap();
  for _ in 0..n {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let friend_mbti = line.trim();
    if jinho_mbti == friend_mbti {
      ans+=1;
    }
  }
  print!("{}", ans);
}