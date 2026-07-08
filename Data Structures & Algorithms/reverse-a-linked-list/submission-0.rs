// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: Option<Box<ListNode>>,
// }
//
// impl ListNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         ListNode { next: None, val }
//     }
// }

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        let mut last = None;
        let mut head = head;

        while let Some(mut node) = head
        {
            let next = node.next;
            node.next = last;
            (last,head) = (Some(node),next);
        }
        return last;
    }
}
