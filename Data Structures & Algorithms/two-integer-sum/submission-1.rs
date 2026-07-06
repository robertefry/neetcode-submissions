
use std::collections::*;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut seen = HashMap::new();

        for (i,num) in nums.into_iter().enumerate()
        {
            if let Some(&j) = seen.get(&(target-num)) {
                return vec![j as i32, i as i32];
            }
            seen.insert(num,i);
        }

        unreachable!()
    }
}
