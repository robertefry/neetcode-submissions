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
    pub fn invert_tree(mut root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>>
    {
        fn invert_inplace(root: &mut Option<Rc<RefCell<TreeNode>>>)
        {
            let Some(node) = root
            else {
                return;
            };
            let node = &mut *node.borrow_mut();

            invert_inplace(&mut node.left);
            invert_inplace(&mut node.right);
            std::mem::swap(&mut node.left, &mut node.right);
        }

        invert_inplace(&mut root);
        return root;
    }
}
