use std::io;

fn main() {
  let mut line = String::new();
  let mut ans1 = 1;
  let mut ans2 = 1;

  io::stdin().read_line(&mut line).expect("wrong io");
  let numbers: Vec<i64> = line
    .split_whitespace()
    .map(|num| num.parse::<i64>().unwrap())
    .collect();

  let mut odd: Vec<i64> = Vec::new();
  let mut even: Vec<i64> = Vec::new();

  for i in numbers {
    if i % 2 == 0 {
      even.push(i);
    }
    else {
      odd.push(i);
    }
  }

  odd.sort();
  even.sort();

  for i in &odd {
    ans1 *= i;
  }

  for i in even {
    ans2 *= i;
  }

  if odd.len() > 0 {
    println!("{}", ans1);
  }
  else {
    println!("{}", ans2);
  }
}
