
use std::collections::*;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32
    {
        let hash: HashSet<_> = nums.iter().cloned().collect();
        let mut max = 0;

        for mut num in nums
        {
            if hash.contains(&(num-1)) {
                continue;
            }

            let mut count = 0;

            while hash.contains(&num) {
                num += 1;
                count += 1;
            }
            max = max.max(count);
        }

        return max;
    }
}
