
use std::{cmp::Ordering, collections::*, hash::Hash, sync::LazyLock};

const PAIRS: LazyLock<HashMap<char,char>> = LazyLock::new(|| HashMap::from([
    ('(', ')'),
    ('[', ']'),
    ('{', '}'),
    ('<', '>'),
    ('|', '|'),
]));

impl Solution {
    pub fn is_valid(s: String) -> bool
    {
        let mut stack = VecDeque::new();

        for c in s.chars()
        {
            // if c is an opening, push it to the stack
            if PAIRS.contains_key(&c) {
                stack.push_front(c);
                continue;
            }

            // otherwise, get the top of the stack, or false if empty
            let Some(top) = stack.pop_front()
            else {
                return false;
            };

            // then, get the closing pair, or false if it doesn't have one
            let Some(&closing) = PAIRS.get(&top)
            else {
                return false;
            };

            // and check c is the closing pair for the top of the stack
            if c != closing {
                return false;
            }
        }

        // true if all openings have been closed
        return stack.is_empty();
    }
}
