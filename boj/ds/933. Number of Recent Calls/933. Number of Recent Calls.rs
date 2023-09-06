use::std::collections::VecDeque;
use std::cell::RefCell;

struct RecentCounter {
     requests: RefCell<VecDeque<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {

    fn new() -> Self {
        RecentCounter {
            requests: RefCell::new(VecDeque::new())
        }
    }
    
    fn ping(&self, t: i32) -> i32 {
        let mut requests = self.requests.borrow_mut();
        requests.push_back(t);

        while let Some(&front) = requests.front() {
            if front < t - 3000 {
                requests.pop_front();
            } else {
                break;
            }
        }
        requests.len() as i32
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */