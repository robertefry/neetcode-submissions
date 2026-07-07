
use std::{cmp::Ordering, collections::*};

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>>
    {
        nums.sort_unstable();

        let n = nums.len();
        let mut result = Vec::new();

        for i in 0..n
        {
            if i > 0 && nums[i] == nums[i-1] {
                continue;
            }
            let (mut l, mut r) = (i+1, n-1);

            while l < r {
                match (nums[i] + nums[l] + nums[r]).cmp(&0) {
                    Ordering::Equal => {
                        result.push(vec![nums[i],nums[l],nums[r]]);
                        while { l += 1; l < r && nums[l] == nums[l-1] }{}
                    },
                    Ordering::Less => {
                        l += 1;
                    },
                    Ordering::Greater => {
                        r -= 1;
                    },
                }
            }
        }

        return result;
    }
}
