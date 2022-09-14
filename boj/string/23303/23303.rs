use std::io;

fn main() {
  let mut ans;
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  match line.find("d2") {
    Some(_) => ans = "D2",
    None => ans = "unrated"
  }
  if ans == "D2" {
    print!("{}", ans);
    return;
  }
  match line.find("D2") {
    Some(_) => ans = "D2",
    None => ans = "unrated",
  }
  print!("{}", ans)
}