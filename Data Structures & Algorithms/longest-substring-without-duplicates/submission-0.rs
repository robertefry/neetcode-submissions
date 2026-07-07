
use std::{cmp::Ordering, collections::*};

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let mut seen = HashSet::<char>::new();
        let mut chrs = VecDeque::<char>::new();
        let mut max_length = 0;

        for c in s.chars()
        {
            while seen.contains(&c)
            {
                let Some(chr) = chrs.pop_front()
                else {
                    unreachable!()
                };
                seen.remove(&chr);
            }

            seen.insert(c);
            chrs.push_back(c);
            max_length = std::cmp::max(max_length, seen.len());
        }

        max_length as i32
    }
}
