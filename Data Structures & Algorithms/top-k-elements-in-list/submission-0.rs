
use std::{collections::*, hash::Hash};

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32>
    {
        let mut counts = nums.into_iter().count_unique();
        let mut result = Vec::new();

        for _ in 0..k {
            let Some((&num,_)) = counts.iter().max_by_key(|&(_,count)| count)
            else {
                unreachable!()
            };
            result.push(num);
            counts.remove(&num);
        }

        return result;
    }
}

pub trait CountUnique<T> {
    fn count_unique(self) -> HashMap<T,usize>;
}

impl<T,I> CountUnique<T> for I
where
    T: Eq + Hash,
    I: Iterator<Item=T>
{
    fn count_unique(self) -> HashMap<T,usize> {
        self.fold(HashMap::new(), |mut counts, elem| {
            *counts.entry(elem).or_default() += 1;
            counts
        })
    }
}
