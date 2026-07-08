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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool
    {
        let mut stack = Vec::from([(p,q)]);

        while let Some((p,q)) = stack.pop()
        {
            if p.is_none() != q.is_none() {
                return false;
            }

            let (Some(p),Some(q)) = (p,q)
            else {
                continue;
            };

            let p = p.borrow();
            let q = q.borrow();

            if p.val != q.val {
                return false;
            }

            stack.push((p.left.clone(),q.left.clone()));
            stack.push((p.right.clone(),q.right.clone()));
        }

        true
    }
}
