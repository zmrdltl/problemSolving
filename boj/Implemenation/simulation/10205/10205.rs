use std::io;
fn main(){
  let mut line = String::new();
  io::stdin().read_line(&mut line).expect("wrong io");
  let test_case = line.trim().parse::<i64>().unwrap();

  for i in 1..test_case+1 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("wrong io");

    let mut head = line.trim().parse::<i64>().unwrap();

    let mut behaving = String::new();
    io::stdin().read_line(&mut behaving).expect("wrong io");
    behaving = behaving.trim().to_string();

    for i in behaving.chars() {
      if i == 'c' {
        head += 1;
      }
      else {
        head -= 1;
      }
    }
    
    print!("Data Set {}:\n{}\n\n", i, head);
  }
}