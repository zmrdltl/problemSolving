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
    pub fn in_order(root: Option<Rc<RefCell<TreeNode>>>, nodes: &mut Vec<i32>) {
        if let Some(node) = root {
            Self::in_order(node.borrow().left.clone(), nodes);
            nodes.push(node.borrow().val);
            Self::in_order(node.borrow().right.clone(), nodes);
        }
    }

    pub fn increasing_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut nodes = vec![];
        Self::in_order(root, &mut nodes);
        
        let mut ans = Rc::new(RefCell::new(TreeNode::new(0)));
        let mut cur = ans.clone();

        for node in nodes {
            cur.borrow_mut().right = Some(Rc::new(RefCell::new(TreeNode::new(node))));
            let next = cur.borrow().right.as_ref().unwrap().clone();
            cur = next;
        }

        let ans = ans.borrow().right.clone();
        ans
    }
}
