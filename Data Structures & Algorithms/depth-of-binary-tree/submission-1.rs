// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//     pub val: i32,
//     pub left: Option<Rc<RefCell<TreeNode>>>,
//     pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         TreeNode {
//             val,
//             left: None,
//             right: None,
//         }
//     }
// }

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32
    {
        let Some(root) = root
        else {
            return 0;
        };

        let mut stack = VecDeque::from([(1,root)]);
        let mut max_depth = 0;

        while let Some((depth,node)) = stack.pop_back()
        {
            let node = node.borrow();

            if let Some(ref left) = node.left {
                stack.push_back((depth+1,left.clone()));
            }
            if let Some(ref right) = node.right {
                stack.push_back((depth+1,right.clone()));
            }
            max_depth = max_depth.max(depth);
        }
        return max_depth;
    }
}
