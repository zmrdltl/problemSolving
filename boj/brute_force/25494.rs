use std::io;
fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let test_case = line.trim().parse::<i32>().unwrap();
  for i in 0..test_case{
    let mut ans = 0;
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");
    let numbers: Vec<i64> = line
      .split_whitespace()
      .map(|num| num.parse::<i64>().unwrap())
      .collect();
    let a = numbers[0];
    let b = numbers[1];
    let c = numbers[2];
    for x in 1..a+1{
      for y in 1..b+1{
        for z in 1..c+1{
          if x%y == y%z && y%z == z%x {
            ans+=1;
          }
        }
      }
    }
    println!("{}",ans);
  }
}