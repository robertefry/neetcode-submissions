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
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>>
    {
        // assumption: the tree is balanced.

        fn find(
            root: Option<Rc<RefCell<TreeNode>>>,
            val: i32,
        ) -> bool
        {
            let Some(root) = root else { return false; };
            return root.borrow().val == val
                || find(root.borrow().left.clone(), val)
                || find(root.borrow().right.clone(), val)
                ;
        }

        let Some(node) = root.clone() else { return None; };
        let n_val = node.borrow().val;

        let Some(p_val) = p.clone().map(|node| node.borrow().val) else { return q; };
        let Some(q_val) = q.clone().map(|node| node.borrow().val) else { return None; };

        // if the root is p or q, check the p and q are in the tree
        if n_val == p_val {
            return find(root.clone(), q_val).then_some(node);
        }
        if n_val == q_val {
            return find(root.clone(), p_val).then_some(node);
        }

        // if p and q are on the same side, recurse to that side
        if std::cmp::max(p_val,q_val) < n_val {
            return Solution::lowest_common_ancestor(node.borrow().left.clone(), p, q);
        }
        if std::cmp::min(p_val,q_val) > n_val {
            return Solution::lowest_common_ancestor(node.borrow().right.clone(), p, q);
        }

        // if p and q are on different sides, we've found our answer
        if std::cmp::min(p_val,q_val) < n_val && n_val < std::cmp::max(p_val,q_val) {
            return root;
        }

        unreachable!()
    }
}
