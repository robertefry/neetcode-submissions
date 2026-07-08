
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>>
    {
        fn take_next<'a, I>(
            mut lists: I,
        ) -> Option<Box<ListNode>>
        where
            I: Iterator<Item = &'a mut Option<Box<ListNode>>>,
        {
            let mut best_list: &mut Option<Box<ListNode>> = &mut None;

            while let Some(curr_list) = lists.next()
            {
                let Some(list_head) = curr_list
                else {
                    continue;
                };

                let Some(best_head) = best_list
                else {
                    best_list = curr_list;
                    continue;
                };

                if list_head.val < best_head.val {
                    best_list = curr_list;
                }
            }

            let Some(mut best_head) = best_list.take()
            else {
                return None;
            };

            *best_list = best_head.next.take();
            return Some(best_head);
        }

        let mut head = None;

        for list in lists
        {
            let mut lists = [head.take(),list];

            let Some(next) = take_next(lists.iter_mut())
            else {
                continue;
            };
            let mut curr = head.insert(next);

            while let Some(next) = take_next(lists.iter_mut()) {
                curr = curr.next.insert(next);
            }
        }
        return head;
    }
}
