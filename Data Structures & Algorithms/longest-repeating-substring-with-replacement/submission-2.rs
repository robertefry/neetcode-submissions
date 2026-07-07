
use std::{cmp::Ordering, collections::*, hash::Hash};

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32
    {
        let (mut l, mut r) = (s.chars(), s.chars());
        let mut counts = HashMap::<char,i32>::new();
        let mut length = 0;
        let mut length_max = 0;

        while let Some(c) = r.next()
        {
            *counts.entry(c).or_default() += 1;
            length += 1;

            loop {
                let Some(subs) = counts.iter()
                    .map(|(_,&count)| length - count)
                    .min()
                else {
                    unreachable!()
                };

                if subs <= k {
                    break;
                }

                let Some(c) = l.next()
                else {
                    unreachable!()
                };

                *counts.entry(c).or_default() -= 1;
                length -= 1;
            }

            length_max = std::cmp::max(length_max, length);
        }

        length_max
    }
}
