// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root, 0)
    }

    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, current: i32) -> i32 {
        if let Some(n) = root {
            let n = n.borrow();
            let new_val = current * 2 + n.val;

            if n.left.is_none() && n.right.is_none() {
                return new_val;
            }

            return Self::dfs(n.left.clone(), new_val) + Self::dfs(n.right.clone(), new_val);
        }
        0
    }
}