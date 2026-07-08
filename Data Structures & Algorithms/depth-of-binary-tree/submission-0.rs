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
        fn max_depth(root: &Option<Rc<RefCell<TreeNode>>>) -> i32
        {
            let Some(node) = root
            else {
                return 0;
            };
            let node = &*node.borrow_mut();

            return 1 + std::cmp::max(
                max_depth(&node.left),
                max_depth(&node.right),
            );
        }
        max_depth(&root)
    }
}
