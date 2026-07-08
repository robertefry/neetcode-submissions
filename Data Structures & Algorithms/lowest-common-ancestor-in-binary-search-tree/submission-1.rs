
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>>
    {
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

        let Some(r_node) = root.clone() else { return None; };
        let r_val = r_node.borrow().val;

        let Some(p_val) = p.clone().map(|node| node.borrow().val) else { return q; };
        let Some(q_val) = q.clone().map(|node| node.borrow().val) else { return p; };
        let min_val = std::cmp::min(p_val,q_val);
        let max_val = std::cmp::max(p_val,q_val);

        // if the root is p or q, check that p and q are in the tree
        if r_val == p_val {
            return find(root, q_val).then_some(r_node);
        }
        if r_val == q_val {
            return find(root, p_val).then_some(r_node);
        }

        // if p and q are on the same side, recurse to that side
        if max_val < r_val {
            return Solution::lowest_common_ancestor(r_node.borrow().left.clone(), p, q);
        }
        if min_val > r_val {
            return Solution::lowest_common_ancestor(r_node.borrow().right.clone(), p, q);
        }

        // if p and q are on different sides, we've found our answer
        if min_val < r_val && r_val < max_val {
            find(r_node.borrow().left.clone(), min_val).then_some(())?;
            find(r_node.borrow().right.clone(), max_val).then_some(())?;
            return root;
        }

        unreachable!("assumption: the tree is balanced")
    }
}
